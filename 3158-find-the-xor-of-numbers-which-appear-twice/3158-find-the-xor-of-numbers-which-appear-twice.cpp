class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        int ans=0;
        vector<int> a;
        for(auto it:m){
            if(it.second==2)a.push_back(it.first);
        }
        for(int i=0;i<a.size();i++){
            if(i==0)ans=a[i];
            else ans^=a[i];
        }
        return ans;
    }
};