class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int st=0,end=n-1;
        int maxpairsum = INT_MIN;
        while(st<end){
            maxpairsum = max(nums[st]+nums[end],maxpairsum);
            st++;
            end--;
        }
        return maxpairsum;
    }
};