class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int l=logs.size();
        sort(logs.begin(),logs.end(),cmp);

        int q=queries.size();
        vector<int> res(q);

        vector<pair<int,int>> v;
        for(int i=0;i<q;i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());

        unordered_map<int,int> m;
        int i=0;
        int j=0;

        for(auto[t,idx]:v){
            int s=t-x;
            int e=t;

            while(j<l && logs[j][1]<=e){
                m[logs[j][0]]++;
                j++;
            }

            while(i<j && logs[i][1]<s){
                m[logs[i][0]]--;
                if(m[logs[i][0]]==0){
                    m.erase(logs[i][0]);
                }
                i++;
            }

            res[idx]=n-m.size();
        }
        return res;
    }
};