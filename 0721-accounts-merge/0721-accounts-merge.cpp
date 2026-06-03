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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(m.find(mail)==m.end()){
                    m[mail]=i;
                }else{
                    unionset(i,m[mail]);
                }
            }
        }

        unordered_map<int,vector<string>> merged;
        for(auto it:m){
            string mail=it.first;
            int acc=it.second;
            int root=find(acc);
            merged[root].push_back(mail);
        }
        vector<vector<string>> ans;
        for(auto it: merged){
            int root=it.first;
            vector<string> mails=it.second;
            sort(mails.begin(),mails.end());

            vector<string> temp;
            temp.push_back(accounts[root][0]);
            for(auto x:mails){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};