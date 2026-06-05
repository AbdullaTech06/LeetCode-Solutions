class Solution {
public:
    int solve(vector<int>& nums,int l,int r){
        int n=r-l+1;
        if(n==1)return nums[l];
        vector<int> dp(n);
        dp[0]=nums[l];
        dp[1]=max(nums[l],nums[l+1]);
        for(int i=2;i<n;i++){
            int pick=nums[l+i]+dp[i-2];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int case1=solve(nums,0,n-2);
        int case2=solve(nums,1,n-1);

        return max(case1,case2);
    }
};