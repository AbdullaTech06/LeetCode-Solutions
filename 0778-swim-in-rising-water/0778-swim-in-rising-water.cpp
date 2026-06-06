class Solution {
public:
    bool canreach(vector<vector<int>>& grid,int t){
        int n=grid.size();
        if(grid[0][0]>t)return false;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        q.push({0,0});
        vis[0][0]=true;

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int r=x.first;
            int c=x.second;
            if(r==n-1 && c==n-1)return true;
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]<=t){
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int low=grid[0][0];
        int high=n*n-1;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(canreach(grid,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};