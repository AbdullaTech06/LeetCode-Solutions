class Solution {
public:
    const int mod=1e9+7;

    int dfs(int i,int j,vector<vector<int>>& grid,int previ,int prevj,vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();

        if(i>=m || j>=n)return 0;
        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(grid[i][j]==1){
            if(prevj==j){
                return dfs(i,j+1,grid,i,j,dp);
            }else if(previ==i){
                return dfs(i+1,j,grid,i,j,dp);
            }
        }
        int down=dfs(i+1,j,grid,i,j,dp);
        int right=dfs(i,j+1,grid,i,j,dp);

        return dp[i][j]=(down+right)%mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(0,0,grid,-1,-1,dp);
    }
};