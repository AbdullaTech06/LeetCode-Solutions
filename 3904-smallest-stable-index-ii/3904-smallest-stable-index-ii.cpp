class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> a(n);
        vector<int> b(n);
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            a[i]=mx;
        }
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            b[i]=mn;
        }

        for(int i=0;i<n;i++){
            if(a[i]-b[i]<=k)return i;
        }
        return -1;
    }
};