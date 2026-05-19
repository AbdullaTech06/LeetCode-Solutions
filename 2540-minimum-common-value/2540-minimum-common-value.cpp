class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int it:nums1){
            s.insert(it);
        }
        for(int i=0;i<nums2.size();i++){
            if(s.count(nums2[i])){
                return nums2[i];
            }
        }
        return -1;
    }
};