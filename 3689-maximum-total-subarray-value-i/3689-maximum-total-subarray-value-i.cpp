class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long mxel=LLONG_MIN;
        long long mnel=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>mxel){
                mxel=nums[i];
            }
            if(nums[i]<mnel){
                mnel=nums[i];
            }
        }
        return (mxel-mnel)*k;
    }
};