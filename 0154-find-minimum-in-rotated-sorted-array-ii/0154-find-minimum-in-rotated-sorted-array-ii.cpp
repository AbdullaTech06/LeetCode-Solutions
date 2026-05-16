class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=INT_MAX;
        int st=0;
        int end=nums.size()-1;

        while(st<=end){
            int mid=st+(end-st)/2;
            mn=min(mn,nums[mid]);
            if(nums[st]==nums[mid] && nums[mid]==nums[end]){
                st++;
                end--;
            }else if(nums[st]<=nums[mid]){
                mn=min(mn,nums[st]);
                st=mid+1;
            }else{
                end=mid-1;
                mn=min(mn,nums[mid]);
            }
        }
        return mn;
    }
};