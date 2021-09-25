// https://www.hackerrank.com/challenges/larrys-array/problem

string larrysArray(vector<int> A) {
    // Let a pair (x, y) be a conversion if 0 <= x < y < len(A) and A[x] > A[y].
    // After a rotation from "ABC" to "BCA" or "CAB", 
    // the parity of number of conversions remain the same.
    
    // Determine if the original array has even or odd number of conversions.
    bool evenInversion = true;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i + 1; j < A.size(); ++j) {
            if (A[i] > A[j])
                evenInversion = !evenInversion;
        }
    }
    
    // It can only be sorted if the number of conversion is even.
    return evenInversion ? "YES" : "NO";
}
