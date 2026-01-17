class Solution {
public:
    int m, n;
    int ans = 0;
    int empty = 0;

    void up(vector<vector<int>>& grid, int r, int c, int remain) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == -1)
            return;

        if (grid[r][c] == 2) {
            if (remain == 0) ans++;
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = -1;  

        // left
        up(grid, r, c - 1, remain - 1);
        // right
        up(grid, r, c + 1, remain - 1);
        // up
        up(grid, r - 1, c, remain - 1);
        // down
        up(grid, r + 1, c, remain - 1);

        grid[r][c] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int strow, stcol;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    strow = i;
                    stcol = j;
                } else if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }

        up(grid, strow, stcol, empty + 1);
        return ans;
    }
};
