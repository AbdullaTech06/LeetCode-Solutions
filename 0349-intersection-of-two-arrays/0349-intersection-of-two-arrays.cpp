class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        unordered_set<int> s3;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(s1.count(nums1[i]) && s2.count(nums1[i])){
                s3.insert(nums1[i]);
            }
        }
        for(auto it : s3){
            ans.push_back(it);
        }
        return ans;
    }
};