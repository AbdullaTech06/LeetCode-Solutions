class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty())return ans;
        int st=nums[0];
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)continue;
            int end=nums[i-1];
            if(st==end)ans.push_back(to_string(st));
            else ans.push_back(to_string(st)+"->"+to_string(end));
            st=nums[i];
        }

        if(st==nums[n-1])ans.push_back(to_string(st));
        else ans.push_back(to_string(st) +"->"+ to_string(nums[n - 1]));

        return ans;
    }
};