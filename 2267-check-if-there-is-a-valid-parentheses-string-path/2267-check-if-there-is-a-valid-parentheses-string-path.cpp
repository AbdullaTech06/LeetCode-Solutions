class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(int i, int j, vector<vector<char>>& grid, int x) {
        if(i>=m || j>=n)return false;
        if(x<0)return false;

        if(grid[i][j]=='(')x++;
        else x--;

        if(x<0)return false;

        if(dp[i][j][x]!=-1)return dp[i][j][x];

        if(i==m-1 && j==n-1)return dp[i][j][x]=(x==0);

        bool down = dfs(i+1, j, grid, x);
        bool right = dfs(i, j+1, grid, x);

        return dp[i][j][x] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if((m+n-1)%2==1)return false;
        dp.assign(m,vector<vector<int>>(n,vector<int>(m+n+1,-1)));

        return dfs(0, 0, grid, 0);
    }
};