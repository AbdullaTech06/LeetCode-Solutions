class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int sum=0;
        int ans=INT_MIN;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(r-l+1>k){
                sum-=nums[l];
                l++;
            }
            if(r-l+1==k){
                ans=max(ans,sum);
            }
        }
        return (double)ans/(double)k;
    }
};