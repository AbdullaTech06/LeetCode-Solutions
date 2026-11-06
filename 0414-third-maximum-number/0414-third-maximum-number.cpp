class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> a;
        for(auto it:s){
            a.push_back(it);
        }
        sort(a.begin(),a.end());
        int n=a.size();
        if(n<3){
            return a[n-1];
        }else{
            return a[n-3];
        }
    }
};