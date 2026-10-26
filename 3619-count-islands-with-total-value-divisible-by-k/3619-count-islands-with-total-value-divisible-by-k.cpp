class Solution {
public:
    typedef long long ll;
    ll dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n || i<0 ||j<0)return 0;
        if(vis[i][j])return 0;
        if(grid[i][j]==0)return 0;
        vis[i][j]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        ll sum=grid[i][j];
        for(int k=0;k<4;k++){
            sum+=dfs(i+dr[k],j+dc[k],grid,vis);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    if(dfs(i,j,grid,vis)%k==0)ans++;
                }
            }
        }
        return ans;
    }
};