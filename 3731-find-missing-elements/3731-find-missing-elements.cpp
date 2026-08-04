class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxval= *max_element(nums.begin(),nums.end());
        int minval= *min_element(nums.begin(),nums.end());
        vector<int> result;
        

        for(int i = minval;i<=maxval;i++){
            int target = i ;
            int found=0;

            for(int j=0;j<nums.size();j++){
                if(nums[j]==target){
                    found = 1;
                    break;
                }
            }
            if(!found){
                result.push_back(i);
                }
        }
        return result;
    }
};