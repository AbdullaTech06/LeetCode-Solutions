class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        int dr[8]={1,0,-1,0,1,-1,-1,1};
        int dc[8]={0,1,0,-1,-1,-1,1,1};
        q.push({{0,0},1});
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int d=it.second;

            if(r==n-1 && c==n-1)return d;

            for(int k=0;k<8;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && d+1<dist[nr][nc]){
                    dist[nr][nc]=d+1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return -1;
    }
};