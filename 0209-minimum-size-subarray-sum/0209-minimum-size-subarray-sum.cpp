class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mn=INT_MAX;
        int l=0;
        int n=nums.size();
        int sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                mn=min(mn,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return mn==INT_MAX?0:mn;
    }
};