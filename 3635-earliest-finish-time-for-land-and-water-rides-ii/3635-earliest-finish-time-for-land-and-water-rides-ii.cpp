class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int mnland=INT_MAX;
        int mnwater=INT_MAX;
        int land_water=INT_MAX;
        int water_land=INT_MAX;
        for(int i=0;i<n;i++){
            mnland=min(mnland,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            mnwater=min(mnwater,waterStartTime[i]+waterDuration[i]);
        }

        for(int i=0;i<m;i++){
            land_water=min(land_water,max(waterStartTime[i],mnland)+waterDuration[i]);
        }
        for(int i=0;i<n;i++){
            water_land=min(water_land,max(landStartTime[i],mnwater)+landDuration[i]);
        }
        
        return min(land_water,water_land);
    }
};