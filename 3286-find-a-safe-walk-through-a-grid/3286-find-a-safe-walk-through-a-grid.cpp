class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> best(m,vector<int>(n,-1));
        int st=health-grid[0][0];
        if(st<=0)return false;

        q.push({{0,0},st});
        best[0][0]=st;

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int h=q.front().second;
            q.pop();

            if(r==m-1 && c==n-1)return true;
           
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr<0 || nr>=m || nc<0 || nc>=n)continue;
                int nh=h-grid[nr][nc];
                if(nh<=0)continue;
                if(nh>best[nr][nc]){
                    best[nr][nc]=nh;
                    q.push({{nr,nc},nh});
                }
            }
        }
        return false;
    }
};