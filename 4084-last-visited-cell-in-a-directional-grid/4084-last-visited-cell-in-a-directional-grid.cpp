class Solution {
public:
    int m;
    int n;
    int r;
    int c;
    void solve(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        if(i>=m || j>=n || i<0 || j<0)return;
        if(vis[i][j])return;
        vis[i][j]=1;
        r=i;
        c=j;
        switch(grid[i][j]){
            case 'L':solve(i,j-1,grid,vis);break;
            case 'R':solve(i,j+1,grid,vis);break;
            case 'U':solve(i-1,j,grid,vis);break;
            case 'D':solve(i+1,j,grid,vis);break;
        }
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        r=0;
        c=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        solve(0,0,grid,vis);
        return {r,c};
    }
};