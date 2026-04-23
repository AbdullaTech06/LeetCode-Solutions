class Solution {
public:
    bool cansplit(vector<int>& nums, int k,int maxsum){
        int cnt=1;
        long long cursum=0;
        for(int x:nums){
            if(cursum+x<=maxsum){
                cursum+=x;
            }else{
                cnt++;
                cursum=x;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int st=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans;

        while(st<=end){
            int mid = st+(end-st)/2;
            if(cansplit(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};