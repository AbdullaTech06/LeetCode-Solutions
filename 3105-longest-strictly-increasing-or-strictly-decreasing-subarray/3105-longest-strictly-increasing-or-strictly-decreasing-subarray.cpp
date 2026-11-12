class Solution {
public:
    bool check(int i,int j,vector<int>& nums){
        bool x=true;
        for(int k=i;k<j;k++){
            if(nums[k]>=nums[k+1]){
                x=false;
            }
        }
        if(x)return true;
        x=true;
        for(int k=i;k<j;k++){
            if(nums[k]<=nums[k+1])x=false;
        }
        if(x)return true;

        return false;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,nums)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};