class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        if(!s.count(0))return true;

        int mxidx=0;
        for(int i=0;i<n;i++){
            if(i>mxidx)return false;
            mxidx=max(mxidx,i+nums[i]);
            if(mxidx>=n-1)return true;
        }
        return false;
    }
};