class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathvis,vector<int>& check){
        vis[node]=1;
        pathvis[node]=1;
        for(int nei:graph[node]){
            if(!vis[nei]){
                if(dfs(nei,graph,vis,pathvis,check))return true;;
            }else if(pathvis[nei]){
                return true;
            }
        }
        pathvis[node]=0;
        check[node]=1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1)ans.push_back(i);
        }
        return ans;
    }
};