
class Solution {
public:
    /*int solve(int i, vector<int>& costs, int n, vector<int>& dp) {
        if(i==n)return 0;
        if(i>n)return 1e9;

        if(dp[i]!=-1)return dp[i];
        int a=1e9,b=1e9,c=1e9;
        if(i+1<=n)a=1+costs[i]+solve(i+1,costs,n,dp);
        if(i+2<=n)b=4+costs[i+1]+solve(i+2,costs,n,dp);
        if(i+3<=n)c=9+costs[i+2]+solve(i+3,costs,n,dp);
        return dp[i]=min({a,b,c});
    }
    */
    
    int climbStairs(int n, vector<int>& costs) {
        //vector<int> dp(n+1,-1);
        //return solve(0,costs,n,dp);
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int a=1e9,b=1e9,c=1e9;
            if(i+1<=n)a=1+costs[i]+dp[i+1];
            if(i+2<=n)b=4+costs[i+1]+dp[i+2];
            if(i+3<=n)c=9+costs[i+2]+dp[i+3];
            dp[i]=min({a,b,c});
        }
        return dp[0];
    }
};
