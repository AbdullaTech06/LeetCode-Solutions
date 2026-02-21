class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0;
        int totalcost = 0;
        int currfuel = 0;
        int st = 0;
        
        for(int i=0;i<gas.size();i++) {
            totalgas+=gas[i];
            totalcost+=cost[i];
            currfuel+=gas[i]-cost[i];
            if(currfuel<0) {
                st=i+1;
                currfuel=0;
            }
        }
        
        if(totalgas<totalcost)
            return -1;
        
        return st;
    }
};