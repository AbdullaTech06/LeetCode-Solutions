class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot<abs(target) || (tot+target)%2){
            return 0;
        }
        int tar=(tot+target)/2;
        vector<int> prev(tar+1,0);
        if(nums[0]==0){
            prev[0]=2;
        }else{
            prev[0]=1;
            if(nums[0]<=tar){
                prev[nums[0]]=1;
            }
        }
        for(int i=1;i<n;i++){
            vector<int> curr(tar+1,0);
            for(int sum=0;sum<=tar;sum++){
                int nottake=prev[sum];
                int take=0;
                if(nums[i]<=sum)take=prev[sum-nums[i]];
                curr[sum]=take+nottake;
            }
            prev=curr;
        }
        return prev[tar];
    }
};