class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(!s.count(nums[i])){
                s.insert(nums[i]);
            }else{
                s.erase(nums[i]);
            }
        }
        vector<int> ans;
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};