class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        bool ans = false;

        for(int x=0;x<n;x++){
            for(int i=0;i<n;i++){
                temp[i]=nums[(i+x)%n];
            }
            if(is_sorted(temp.begin(),temp.end())){
                ans=true;
                break;
            }
        }
        return ans;
    }
};