class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        int mod=1e9+7;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            long long d=x.first;
            int node=x.second;
            if(d>dist[node])continue;
            for(auto it : adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                    ways[adjnode]=ways[node]%mod;
                }else if(d+wt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};