// https://www.hackerrank.com/challenges/bomber-man/problem

vector<string> bomberMan(int n, vector<string> grid) {
    // Nothing happens
    if (n == 0 || n == 1)
        return grid;
    
    int r = grid.size(), c = grid[0].size();
    
    // After 2, 4, 6,... seconds, the whole matrix are bombs
    if (n % 2 == 0) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                grid[i][j] = 'O';
            }
        }
        return grid;
    }
    
    int di[] = {-1, 0, 0, 1};
    int dj[] = {0, -1, 1, 0};
    
    string sample = "";
    for (int i = 0; i < c; ++i)
        sample += '.';
    vector<string> affected(r, sample);
    
    // Find the affected cells if the initial bombs exploded.
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == 'O') {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                        affected[ni][nj] = 'O';
                    }
                }
                affected[i][j] = 'O';
            }
        }
    }
    
    // After 3 seconds, all affected cells will become '.'
    
    // After 5 seconds, the unaffected cells (now filled with bombs) are exploded.
    // Consider all affected cells:
    //   + If adjacent to an unaffected one (let's call it hybrid), it will become '.'
    //   + Otherwise: It remains bomb.
    // It means that the remaining bombs after 5 seconds include
    // intital bombs and affected cells that are not hybrid.
    
    // After 7 seconds, these bombs explode. Unaffected cells remain 'O',
    // but the hybrid ones become '.'
    // meaning that it goes back to the stage after 3 secs.
    
    // After 9 seconds, the unaffected cells are exploded, same as stage after 5 secs.
    
    // --> We have found a pattern.
    
    if (n % 4 == 3) {
        // Affected cells become '.' while unaffected becomes 'O'.
        // Hence we reverse all cells.
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                affected[i][j] = (affected[i][j] == '.') ? 'O': '.';
            }
        }
        return affected;
    }
    
    // Initial bombs and non-hybrid affected cells remain 'O'.
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (affected[i][j] == 'O') {
                bool hybrid = false;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c && affected[ni][nj] == '.') {
                        hybrid = true;
                        break;
                    }
                }
                if (hybrid) {
                    // Hybrid cells
                    grid[i][j] = '.';
                } else {
                    // Initial bombs or non-hybrid
                    grid[i][j] = 'O';
                }
            } else {
                // Unaffected cells
                grid[i][j] = '.';
            }
        }
    }
    return grid;
}
