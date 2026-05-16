class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tsum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int n=cardPoints.size();
        int l=0;
        int ans=INT_MIN;
        int csum=0;
        if(k==n)return tsum;
        for(int r=0;r<n;r++){
            csum+=cardPoints[r];
            if((r-l+1)==n-k){
                ans=max(ans,tsum-csum);
                csum-=cardPoints[l];
                l++;
            }
        }
        return ans;
    }
};