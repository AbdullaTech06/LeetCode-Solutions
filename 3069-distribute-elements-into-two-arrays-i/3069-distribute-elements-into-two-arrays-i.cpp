class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a , b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i = 2 ; i < n ; i++){
            if(a[a.size()-1] > b[b.size()-1]){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }

        vector<int> ans;
        for(int i = 0 ; i < a.size() ; i++){
            ans.push_back(a[i]);
        }
        for(int i = 0 ; i < b.size() ; i++){
            ans.push_back(b[i]);
        }

        return ans;
    }
};