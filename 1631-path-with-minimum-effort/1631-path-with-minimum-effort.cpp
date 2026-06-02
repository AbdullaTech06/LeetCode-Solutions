class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int r=it.second.first;
            int c=it.second.second;
            int w=it.first;
            if(r==n-1 && c==m-1)return w;

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newwt=max(w,abs(heights[nr][nc]-heights[r][c]));
                    if(newwt<dist[nr][nc]){
                    dist[nr][nc]=newwt;
                    pq.push({newwt,{nr,nc}});
                }
                }
            }
        }
        return 0;
    }
};