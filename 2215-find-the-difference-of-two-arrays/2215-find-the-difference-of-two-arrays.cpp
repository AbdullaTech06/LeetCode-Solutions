class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());

        vector<vector<int>> ans(2);
        unordered_set<int> ans1;
        unordered_set<int> ans2;

        for(auto x:s1){
            for(auto y:s2){
                if(s2.find(x)==s2.end()){
                    ans1.insert(x);
                }
                if(s1.find(y)==s1.end()){
                    ans2.insert(y);
                }
            }
        }
        for(auto it:ans1){
            ans[0].push_back(it);
        }
        for(auto it:ans2){
            ans[1].push_back(it);
        }
        return ans;
    }
};