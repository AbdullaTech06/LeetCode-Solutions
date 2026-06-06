class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);
        vector<int> ans(n);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                leftsum[i]+=nums[j];
            }
            for(int j=i+1;j<n;j++){
                rightsum[i]+=nums[j];
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(leftsum[i]-rightsum[i]);
        }
        return ans;
    }
};