class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int tsum=accumulate(nums.begin(),nums.end(),0);
        int tar=tsum-x;
        if(tar<0)return -1;
        if(tar==0)return nums.size();

        int mxlen=-1;
        int csum=0;
        int l=0;
        for(int r=0;r<n;r++){
            csum+=nums[r];

            while(csum>tar && l<r){
                csum-=nums[l];
                l++;
            }
            if(csum==tar){
                mxlen=max(mxlen,r-l+1);
            }
        }
        return mxlen==-1?-1:n-mxlen;
    }
};