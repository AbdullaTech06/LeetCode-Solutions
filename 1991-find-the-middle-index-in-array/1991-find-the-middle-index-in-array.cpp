class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int tsum=accumulate(nums.begin(),nums.end(),0);
        int csum=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(2*csum==tsum-nums[i]){
                ans=i;
                break;
            }
            csum+=nums[i];
        }
        return ans;
    }
};