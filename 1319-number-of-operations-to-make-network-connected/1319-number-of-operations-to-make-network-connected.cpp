class Solution {
public:
    vector<int> parent,rank;
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
        }else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        if(connections.size()<n-1)return -1;
        for(int i=0;i<n;i++)parent[i]=i;
        for(auto it : connections){
            unionset(it[0],it[1]);
        }
        int cmp=0;
        for(int i=0;i<n;i++){
            if(find(i)==i)cmp++;
        }
        return cmp-1;
    }
};