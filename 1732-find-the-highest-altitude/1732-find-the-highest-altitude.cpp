class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<gain.size();i++){
            ans=max(ans,sum);
            sum+=gain[i];
        }
        ans=max(ans,sum);
        return ans;
    }
};