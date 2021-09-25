// https://www.hackerrank.com/challenges/two-pluses/problem

int r, c;

bool isValidLength(int i, int j, int l) {
    return i >= l && i + l < r && j >= l && j + l < c;
}

bool checkAll(int i, int j, int l, char c, vector<string>& grid) {
    return grid[i - l][j] == c && grid[i + l][j] == c && grid[i][j - l] == c && grid[i][j + l] == c;
}

int twoPluses(vector<string> grid) {
    r = grid.size();
    c = grid[0].size();
    
    int maximumProduct = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'B')
                continue;
            
            // For each good cell, find every length of the possible plus centered at it
            int l = 0;
            while (isValidLength(i, j, l) && checkAll(i, j, l, 'G', grid)) {
                // Mark that these cells are occupied
                grid[i - l][j] = grid[i + l][j] = grid[i][j - l] = grid[i][j + l] = 'g';
                
                // Find the second plus
                for (int ni = 0; ni < r; ++ni) {
                    for (int nj = 0; nj < c; ++nj) {
                        if (grid[ni][nj] != 'G')
                            continue;
                        
                        // Keep finding the largest length without intervention
                        int nl = 0;
                        while (isValidLength(ni, nj, nl) && checkAll(ni, nj, nl, 'G', grid)) {
                            nl++;
                        }
                        nl--;
                        maximumProduct = max(maximumProduct, (l * 4 + 1) * (nl * 4 + 1));
                    }
                }
                ++l;
            }
            
            // Restore the occupied cells of the first plus.
            --l;
            while (l >= 0) {
                grid[i - l][j] = grid[i + l][j] = grid[i][j - l] = grid[i][j + l] = 'G';
                --l;
            }
        }
    }
    return maximumProduct;
}
