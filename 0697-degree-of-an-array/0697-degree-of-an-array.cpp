class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq,first,last;

        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(!first.count(x))first[x] = i;
            last[x]=i;
            freq[x]++;
        }

        int degree=0;
        for(auto &p:freq)degree=max(degree, p.second);

        int ans=nums.size();
        for(auto &p : freq){
            int x=p.first;
            if(p.second==degree){
                ans=min(ans,last[x]-first[x]+1);
            }
        }
        return ans;
    }
};