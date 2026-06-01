class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.rbegin(),cost.rend());
        int i=0;
        int tcost=0;
        int f=2;
        for(int i=0;i<n;i++){
            tcost+=cost[i];
            if(i==f){
                tcost-=cost[i];
                f+=3;
            }
        }
        return tcost;
    }
};