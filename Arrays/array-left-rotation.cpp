// https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem

vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    
    // Reverse the whole array
    int left = 0, right = n - 1;
    while (left < right)
        swap(a[left++], a[right--]);
    
    d %= n;
    
    // Reverse the last d element
    left = n - d, right = n - 1;
    while (left < right)
        swap(a[left++], a[right--]);
    
    // Reverse the first n-d element
    left = 0, right = n - d - 1;
    while (left < right)
        swap(a[left++], a[right--]);
    return a;
}
