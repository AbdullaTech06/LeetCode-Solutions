class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int stops=x.first;
            int node=x.second.first;
            int cost=x.second.second;
            
            if(stops>k)continue;

            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;

                if(cost+wt<dist[adjnode] && stops<=k){
                    dist[adjnode]=cost+wt;
                    q.push({stops+1,{adjnode,cost+wt}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};