class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> parent(n);

        int mx=1;
        int lastidx=0;

        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                lastidx=i;
            }
        }
        while(parent[lastidx]!=lastidx){
            ans.push_back(nums[lastidx]);
            lastidx=parent[lastidx];
        }
        ans.push_back(nums[lastidx]);
        reverse(ans.begin(),ans.end());

        return ans;
    }
};