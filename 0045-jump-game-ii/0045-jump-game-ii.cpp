class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        int l=0;
        int r=0;
        while(r<n-1){
            int mx=0;
            for(int i=l;i<=r;i++){
                mx=max(mx,i+nums[i]);
            }
            l=r+1;
            r=mx;
            jumps++;
        }
        return jumps;
    }
};