class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mnidx=-1;
        int mxidx=-1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxidx=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                mnidx=i;
            }
        }

        int x=max(mxidx,mnidx);
        int y=n-x;             
        int z=min(mxidx,mnidx); 

        int both=z+1+n-x;

        return min({x+1,n-z,both});
    }
};