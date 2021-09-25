// https://www.hackerrank.com/challenges/matrix-rotation-algo/problem

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size(), n = matrix[0].size();
    
    // Indicate the up, down rows and left, right columns of the current layer.
    int up = 0, down = m - 1, left = 0, right = n - 1;
    
    // Make sure that the layer is still valid.
    while (up < down && left < right) {
        int w = right - left + 1, h = down - up + 1;
        int len = 2 * (w + h) - 4; // Total cells in this layer
        int rotation = r % len;
        
        while (rotation--) {
            // Keep the up left corner
            int upLeft = matrix[up][left];
            
            // Rotate up row
            for (int j = left; j < right; ++j) {
                matrix[up][j] = matrix[up][j + 1];
            }
            
            // Rotate right row
            for (int i = up; i < down; ++i) {
                matrix[i][right] = matrix[i + 1][right];
            }
            
            // Rotate down row
            for (int j = right; j > left; --j) {
                matrix[down][j] = matrix[down][j - 1];
            }
            
            // Rotate left row, except for the last (nearest the corner)
            for (int i = down; i > up + 1; --i) {
                matrix[i][left] = matrix[i - 1][left];
            }
            matrix[up + 1][left] = upLeft;
        }
        
        // Move to next layer
        up++, down--, left++, right--;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
