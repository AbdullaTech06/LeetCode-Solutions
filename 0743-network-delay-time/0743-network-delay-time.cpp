class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int wt=x.first;
            int node=x.second;
            if(wt>dist[node])continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(wt+w<dist[adjnode]){
                    dist[adjnode]=wt+w;
                    pq.push({wt+w,adjnode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            mx=max(mx,dist[i]);
        }
        return mx;
    }
};