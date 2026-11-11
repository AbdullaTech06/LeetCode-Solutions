class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long x=min(cost1+cost2,costBoth);
        long long y=min(need1,need2);
        long long ans=0;
        ans+=x*y;
        need1-=y;
        need2-=y;
        y=min(cost1,costBoth);
        if(need1>0)ans+=y*need1;
        y=min(cost2,costBoth);
        if(need2>0)ans+=y*need2;
        /*while(y--){
            ans+=x;
            need1--;
            need2--;
        }
        y=min(cost1,costBoth);
        while(need1--){
            ans+=y;
        }
        y=min(cost2,costBoth);
        while(need2--){
            ans+=y;
        }
        */
        return ans;
    }
};