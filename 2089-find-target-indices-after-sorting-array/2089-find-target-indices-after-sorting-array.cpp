class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto li=lower_bound(nums.begin(),nums.end(),target);
        auto ri=upper_bound(nums.begin(),nums.end(),target);
        int l=li-nums.begin();
        int r=ri-nums.begin();
        vector<int> ans;
        while(l<r){
            ans.push_back(l++);
        }
        return ans;
    }
};