class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int left =0,cnt=0;
        unordered_map<int,int> m;
        for(int right=0;right<nums.size();right++){
            if(m[nums[right]]==0){
                k--;
            }
            m[nums[right]]++;

            while(k<0){
                m[nums[left]]--;
                if(m[nums[left]]==0){
                    k++;
                }
                left++;
            }
            cnt+=(right-left+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};