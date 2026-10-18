class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=edges.size()+1;
        vector<int> degree(n,0);
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            degree[u]++;
            degree[v]++;
            if(colors[u]==colors[v])return -1;

            if((colors[u]=='R' && colors[v]=='B')
            ||(colors[u]=='B' && colors[v]=='W')
            ||(colors[u]=='W' && colors[v]=='R'))
            indegree[v]++;

            if((colors[v]=='R' && colors[u]=='B')
            ||(colors[v]=='B' && colors[u]=='W')
            ||(colors[v]=='W' && colors[u]=='R'))
            indegree[u]++;
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                if(root!=-1)return -1;
                    root=i;
                }
            }
        if(root!=-1 && degree[root]<=2)return root;

        return -1;
    }
};