class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> d(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            int x=min(a,b);
            int y=max(a,b);

            d[2]+=2;
            d[2*limit+1]-=2;

            d[x+1]-=1;
            d[y+1+limit]+=1;

            d[a+b]-=1;
            d[a+b+1]+=1;

        }
        int ans=INT_MAX;
        int curr=0;
        for(int s=2;s<=2*limit;s++){
            curr+=d[s];
            ans=min(ans,curr);
        }
        return ans;
    }
};