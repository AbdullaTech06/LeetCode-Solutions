class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,greater,equal;
        for(int x:nums){
            if(x<pivot)less.push_back(x);
            else if(x>pivot)greater.push_back(x);
            else equal.push_back(x);
        }
        vector<int> ans;
        for(int i=0;i<less.size();i++){
            ans.push_back(less[i]);
        }
        for(int i=0;i<equal.size();i++){
            ans.push_back(equal[i]);
        }
        for(int i=0;i<greater.size();i++){
            ans.push_back(greater[i]);
        }
        return ans;
    }
};