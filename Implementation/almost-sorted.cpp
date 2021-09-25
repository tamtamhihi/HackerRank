// https://www.hackerrank.com/challenges/almost-sorted/problem

void almostSorted(vector<int> arr) {
    vector<int> copyArr = arr;
    sort(copyArr.begin(), copyArr.end());
    
    // Find the first, last and the number of wrong positions.
    int firstWrong = -1;
    int lastWrong = -1;
    int wrongCount = 0;
    
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != copyArr[i]) {
            if (firstWrong == -1)
                firstWrong = i;
            lastWrong = i; // Finally it will keep the last wrong index.
            wrongCount += 1;
        }
    }
    
    // Already sorted.
    if (wrongCount == 0) {
        cout << "yes";
        return;
    }
    
    // Exactly 2 positions are wrong, so we only need to swap these.
    if (wrongCount == 2) {
        cout << "yes\nswap " << firstWrong + 1 << " " << lastWrong + 1;
        return;
    }
    
    // Otherwise, the only choice left is to reverse this segment.
    int left = firstWrong, right = lastWrong;
    while (left < right) {
        swap(arr[left++], arr[right--]);
    }
    
    // Check again if it's sorted.
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != copyArr[i]) {
            cout << "no";
            return;
        }
    }
    
    cout << "yes\nreverse " << firstWrong + 1 << " " << lastWrong + 1;
}
