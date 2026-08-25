class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int x=1;
        while(k*x<=mx){
            if(!s.count(k*x))return k*x;
            x++;
        }
        return k*x;
    }
};