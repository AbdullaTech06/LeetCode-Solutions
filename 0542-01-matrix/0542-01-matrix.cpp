class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans= vis;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            ans[r][c]=d;
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return ans;
    }
};