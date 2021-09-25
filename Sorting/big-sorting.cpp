// https://www.hackerrank.com/challenges/big-sorting/problem

// Write a comparing function to compare 2 strings of integers.
bool compareIntString(string& a, string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return 0;
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), compareIntString);
    return unsorted;
}
