class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int txor=0;
        bool allzero=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)allzero=false;
            txor^=nums[i];
        }
        if(txor!=0){
            return nums.size();
        }
        if(allzero)return 0;
        return nums.size()-1;
    }
};