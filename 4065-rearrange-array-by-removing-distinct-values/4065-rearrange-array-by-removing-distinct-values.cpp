class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        vector<int> ans;
        for(auto it:nums){
            m[it]++;
        }
        while(ans.size()!=n){
            int st=ans.size();
            for(auto &it:m){
                if(it.second>=1){
                    ans.push_back(it.first);
                    it.second--;
                }
            }
            sort(ans.begin()+st,ans.end());
        }
        return ans;
    }
};