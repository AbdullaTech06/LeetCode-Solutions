class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;
    int LOG;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        up[node][0]=parent;

        for(int i=1;i<LOG;i++){
            up[node][i]=up[up[node][i - 1]][i - 1];
        }

        for(int nxt:adj[node]){
            if(nxt==parent)continue;
            depth[nxt]=depth[node]+1;
            dfs(nxt,node,adj);
        }
    }

    int lca(int a, int b){
        if (depth[a]<depth[b]) swap(a, b);

        int diff=depth[a]-depth[b];

        for(int i=LOG-1;i>=0;i--){
            if(diff & (1 << i))
                a=up[a][i];
        }

        if(a==b)return a;

        for(int i=LOG-1;i>=0;i--) {
            if(up[a][i]!=up[b][i]){
                a=up[a][i];
                b=up[b][i];
            }
        }
        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n=edges.size()+1;

        vector<vector<int>> adj(n+1);

        for(auto& e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = 1;
        while((1<<LOG)<=n)LOG++;

        up.assign(n+1, vector<int>(LOG));
        depth.assign(n+ 1,0);

        dfs(1,1,adj);

        pow2.assign(n + 1, 1);
        for(int i=1;i<=n;i++){
            pow2[i]=(pow2[i-1]*2)%MOD;
        }

        vector<int> ans;
        for(auto& q:queries){
            int u = q[0];
            int v = q[1];
            int p = lca(u,v);
            int len=depth[u]+depth[v]-2*depth[p];

            if(len == 0)ans.push_back(0);
            else ans.push_back((int)pow2[len - 1]);
        }
        return ans;
    }
};