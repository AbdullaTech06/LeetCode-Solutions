class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int avg = accumulate(nums.begin()+i+1,nums.end(),0)/(n-i-1);
            if(nums[i]>avg){
                cnt++;
            }
        }
        return cnt;
    }
};