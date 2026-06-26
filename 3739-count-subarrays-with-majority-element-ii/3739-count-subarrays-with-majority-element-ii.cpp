class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        m[0]=1;
        int csum=0;
        long long vlpts=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                vlpts+=m[csum];
                csum++;
            }else{
                csum--;
                vlpts-=m[csum];
            }
            m[csum]++;
            ans+=vlpts;
        }
        return ans;
    }
};