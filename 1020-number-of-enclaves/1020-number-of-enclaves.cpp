class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][n-1]==1 && !vis[i][n-1]){
                dfs(i,n-1,grid,vis);
            }
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }
            if(grid[m-1][j]==1 && !vis[m-1][j]){
                dfs(m-1,j,grid,vis);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};