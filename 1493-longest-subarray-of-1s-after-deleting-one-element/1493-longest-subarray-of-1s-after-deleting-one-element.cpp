class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int cnt0=0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(nums[r]==0)cnt0++;
            if(cnt0>1){
                if(nums[l]==0)cnt0--;
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};