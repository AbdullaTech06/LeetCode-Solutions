class Solution {
public:
    int n;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    bool check(vector<vector<int>>& dist,int sf){
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]=1;
        if(dist[0][0]<sf)return false;

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            if(r==n-1 && c==n-1)return true;

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

            if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
            if(vis[nr][nc])continue;
            if(dist[nr][nc]<sf) continue;

                q.push({nr,nc});
                vis[nr][nc]=1;
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int lvl=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                dist[r][c]=lvl;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr<0 || nr>=n || nc<0 || nc>=n || vis[nr][nc])continue;

                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
            lvl++;
        }

        int l=0;
        int r=2*(n-1);
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(dist,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};