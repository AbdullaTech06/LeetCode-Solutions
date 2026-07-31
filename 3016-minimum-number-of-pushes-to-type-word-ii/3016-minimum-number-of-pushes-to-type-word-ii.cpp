class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b){
        return a.second>b.second;
    }

    int minimumPushes(string word) {
        unordered_map<char,int> freq;
        for(char ch:word){
            freq[ch]++;
        }
        vector<pair<char,int>> v;
        for(auto it:freq){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=(i/8+1)*v[i].second;
            
        }
        return ans;
    }
};