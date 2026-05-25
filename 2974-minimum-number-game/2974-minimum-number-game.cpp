class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(ans.size()<n){
            ans.push_back(nums[j]);
            ans.push_back(nums[i]);
            i+=2;
            j+=2;
        }
        return ans;
    }
};