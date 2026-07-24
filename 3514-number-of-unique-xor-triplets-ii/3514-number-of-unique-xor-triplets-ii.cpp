class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s1.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> s2;
        for(auto it:s1){
            for(int i=0;i<n;i++){
                s2.insert(it^nums[i]);
            }
        }
        return s2.size();
    }
};