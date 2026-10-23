class Solution {
public:
    int solve(int x,int n,vector<int>& dp){
        if(x==n)return 1;
        if(x>n)return 0;
        if(dp[x]!=-1)return dp[x];
        return dp[x]=solve(x+1,n,dp)+solve(x+2,n,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(0,n,dp);
    }
};