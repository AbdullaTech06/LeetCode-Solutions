class Solution {
public:
    typedef tuple<int,int,int> T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<vector<int>>> adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<vector<int>> res(n,vector<int>(k+1,INT_MAX));
        priority_queue<T,vector<T>,greater<T>> pq;
        res[0][1]=0;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [d,node,cnt]=pq.top();
            pq.pop();

            if(d>res[node][cnt])continue;
            if(node==n-1)return d;

            for(auto x:adj[node]){
                int adjnode=x[0];
                int wt=x[1];

                int newcnt=(labels[adjnode]==labels[node]?cnt+1:1);
                if(newcnt>k)continue;

                int newdist=d+wt;
                if(newdist<res[adjnode][newcnt]){
                    res[adjnode][newcnt]=newdist;
                    pq.push({newdist,adjnode,newcnt});
                }
            }
        }
        return -1;
    }
};