class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int x : nums)freq[x]++;
        int ans = 0;

        for(auto &[x, cnt]:freq){
            int y=k-x;
            if(freq.find(y)==freq.end())continue;
            if(x==y) ans+=freq[x]/2;
            else if(x<y)ans+=min(freq[x],freq[y]);
        }
        return ans;
    }
};