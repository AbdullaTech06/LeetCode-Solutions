class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
                int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                int profit=0;
                if(b){
                    profit=max(dp[i+1][0]-prices[i]-fee,dp[i+1][1]);
                }else{
                    profit=max(dp[i+1][1]+prices[i],dp[i+1][0]);
                }
                dp[i][b]=profit;
            }
        }
        return dp[0][1];

    }
};