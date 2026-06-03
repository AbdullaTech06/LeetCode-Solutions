class Solution {
public:
    vector<int> parent,rank,size;
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void unionset(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv)return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
            rank[pu]++;
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        parent.resize(n*n);
        rank.resize(n*n,0);
        size.resize(n*n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int node=n*i+j;
                parent[node]=node;
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                int node=i*n+j;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int adjnode=nr*n+nc;
                        unionset(adjnode,node);
                    }                
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                unordered_set<int> st;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        st.insert(find(nr*n+nc));
                    }
                }
                int cursize=1;
                for(auto it:st){
                    cursize+=size[it];
                }
                ans=max(ans,cursize);
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,size[find(i)]);
        }
        return ans;
    }
};