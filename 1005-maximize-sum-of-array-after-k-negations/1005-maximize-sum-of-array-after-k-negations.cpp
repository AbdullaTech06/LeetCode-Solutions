class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0 && k>0){
                k--;
                nums[i]=-nums[i];
            }
        }
        if(k%2==0){
            return accumulate(nums.begin(),nums.end(),0);
        }else{
            sort(nums.begin(),nums.end());
            nums[0]=-nums[0];
            return accumulate(nums.begin(),nums.end(),0);
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};