class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){

                int landfinish=landStartTime[i]+landDuration[i];
                int waterbegin=max(landfinish, waterStartTime[j]);
                ans=min(ans,waterbegin+waterDuration[j]);
                
                int waterfinish=waterStartTime[j]+waterDuration[j];
                int landbegin=max(waterfinish, landStartTime[i]);
                ans=min(ans,landbegin+landDuration[i]);
            }
        }
        return ans;
    }
};