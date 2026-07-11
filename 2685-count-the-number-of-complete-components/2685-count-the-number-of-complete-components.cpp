class Solution {
public:

    void dfs(int node,int& nodes,int& degreesum,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=true;
        nodes++;
        degreesum+=adj[node].size();
        for(int nei:adj[node]){
            if(!vis[nei]){
                dfs(nei,nodes,degreesum,vis,adj);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes=0;
                int degreesum=0;
                dfs(i,nodes,degreesum,vis,adj);
                
                int edgecount=degreesum/2;
                if(edgecount==nodes*(nodes-1)/2)ans++;
            }
        }
        return ans;
    }
};