class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& adj,int u,vector<int>& vis,int& ans){
        for(auto &it:adj[u]){
            int v=it.first;
            int d=it.second;
            ans=min(ans,d);
            vis[u]=1;
            if(!vis[v]){
                dfs(adj,v,vis,ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<int> vis(n+1,0);
        int ans=INT_MAX;
        dfs(adj,1,vis,ans);
        return ans;
    }
}; 