class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(int nei:adj[node]){
            if(!vis[nei])dfs(nei,vis,adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n,0);
        dfs(k,vis,adj);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i])ans.push_back(i);
        }
        for(auto &e : invocations){
            int u=e[0],v=e[1];
            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i=0;i<n;i++)ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};