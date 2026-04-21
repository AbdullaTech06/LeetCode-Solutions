class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = *max_element(nums.begin(),nums.end());
        int st = 1;
        int end = mx;
        int ans=0;
        while(st<=end){
            int mid = st +(end-st)/2;
            int sum =0;
            for(int i=0;i<nums.size();i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum<=threshold){
                ans = mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};