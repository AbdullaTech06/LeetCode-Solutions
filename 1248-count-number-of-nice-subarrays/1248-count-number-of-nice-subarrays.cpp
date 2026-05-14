class Solution {
public:
    int atmost(vector<int> &nums,int goal){
        if(goal<0)return 0;
        int l=0;
        int sum=0;
        int ans=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r]%2;
            while(sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};