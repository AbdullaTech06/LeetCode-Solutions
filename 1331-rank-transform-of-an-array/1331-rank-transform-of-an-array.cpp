class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        set<int> s(arr.begin(),arr.end());
        unordered_map<int,int> m;
        int r=1;
        for(auto it:s){
            m[it]=r;
            r++;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=m[arr[i]];
        }
        return ans;
    }
};