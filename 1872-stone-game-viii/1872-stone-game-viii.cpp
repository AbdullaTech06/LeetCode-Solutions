class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        long long sum=0;

        for(int x:stones)sum += x;
        long long dp=sum;

        for(int i=n-1;i>=2;i--){
            sum-=stones[i];
            dp=max(dp,sum-dp);
        }
        return dp;
    }
};