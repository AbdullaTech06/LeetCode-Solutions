class Solution {
public:
    bool check(vector<int>& nums,vector<int>& v,int k){
        for(int i=0;i<nums.size();i+=k){
            int x=0;
            int xidx=-1;
            for(int j=0;j<k-1;j++){
                if(nums[i+j]>nums[i+j+1]){
                    x++;
                    xidx=j;
                }
            }
            if(x>1)return false;
            if(x==1 && nums[i+k-1]>nums[i])return false;
            int st=(x==0)?0:xidx+1;

            for(int j=0;j<k;j++){
                if(nums[i+(st+j)%k]!=v[i+j])return false;
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> v=nums;
        sort(v.begin(),v.end());
        vector<int> k;
        for(int i=1;i<=n;i++){
            if(n%i==0)k.push_back(i);
        }
        int ans=0;
        for(int i=0;i<k.size();i++){
            int x=k[i];
            if(check(nums,v,x))ans+=x;
        }
        return ans;
    }
};