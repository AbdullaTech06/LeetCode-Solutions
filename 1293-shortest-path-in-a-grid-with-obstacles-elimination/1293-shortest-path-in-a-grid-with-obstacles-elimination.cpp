class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(k>=m*n-2)return m+n-2;
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
        queue<tuple<int,int,int>> q;
        q.push({0,0,k});
        vis[0][0][k]=true;
        int steps=0;
        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,1,-1};

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto[r,c,rem]=q.front();
                q.pop();
                if(r==m-1 && c==n-1)return steps;

                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        int nrem=rem-grid[nr][nc];
                        if(nrem<0)continue;
                        if(vis[nr][nc][nrem])continue;
                        vis[nr][nc][nrem]=true;
                        q.push({nr,nc,nrem});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};