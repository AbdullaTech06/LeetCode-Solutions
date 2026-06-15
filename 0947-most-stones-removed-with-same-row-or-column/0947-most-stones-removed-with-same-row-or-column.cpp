class DSU {
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0;i<n;i++)parent[i] = i;
    }

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b)return;
        if(rank[a]<rank[b])swap(a,b);

        parent[b]=a;
        if(rank[a]==rank[b])rank[a]++;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        DSU dsu(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dsu.unite(i,j);
                }
            }
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i)components++;
        }
        return n-components;
    }
};