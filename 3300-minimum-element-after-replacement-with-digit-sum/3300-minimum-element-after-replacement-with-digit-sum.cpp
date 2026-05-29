class Solution {
public:
    int sum(int x){
        int t=x;
        int s=0;
        while(t>0){
            s+=t%10;
            t/=10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,sum(nums[i]));
        }
        return mn;
    }
};