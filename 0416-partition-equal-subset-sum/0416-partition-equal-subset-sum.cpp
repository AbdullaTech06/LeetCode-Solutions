class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2==1)return false;
        int s=total/2;
        vector<bool> dp(s+1,false);
        dp[0]=true;
        for(int x:nums){
            for(int sum=s;sum>=x;sum--){
                dp[sum]=dp[sum]||dp[sum-x];
            }
        }
        return dp[s];
    }
};