// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

class DSU {
private:
    int n;
    vector<int> parent;
    vector<int> rank;
    int getParent(int u) {
        if (u != parent[u])
            parent[u] = getParent(parent[u]);
        return parent[u];
    }
public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    void unionFind(int u, int v) {
        int up = getParent(u);
        int vp = getParent(v);
        if (up == vp)
            return;
        if (rank[up] > rank[vp]) {
            parent[vp] = up;
        } else if (rank[up] < rank[vp]) {
            parent[up] = vp;
        } else {
            rank[up]++;
            parent[vp] = up;
        }
    }
    unordered_map<int, int> getGroupsSize() {
        // Map a root parent with its group's size.
        unordered_map<int, int> size;
        for (int i = 0; i < n; ++i) {
            int ip = getParent(i);
            size[ip] += 1;
        }
        // Map each size with the number of different groups sharing this size.
        unordered_map<int, int> groups;
        for (auto& p : size) {
            groups[p.second] += 1;
        }
        return groups;
    }
};

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    DSU dsu(n);
    for (vector<int>& pair : astronaut) {
        dsu.unionFind(pair[0], pair[1]);
    }
    
    unsigned long long answer = 0;
    unordered_map<int, int> groups = dsu.getGroupsSize();
    
    // For each member in a group, it can be paird with <n - groupSize> other astronauts.
    for (auto& p : groups) {
        int groupSize = p.first, numGroup = p.second
        answer += 1LL * groupSize * (n - groupSize) * numGroup;
    }
    
    // The pair (a, b) are duplicately calculated from both sides, so we must divide 2.
    return answer / 2;
}
