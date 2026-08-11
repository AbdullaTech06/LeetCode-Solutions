class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }else{
                break;
            }
        }
        unordered_set<int> s(nums.begin(),nums.end());
        while(1){
            if(s.find(sum)==s.end()){
                return sum;
            }else{
                sum++;
            }
        }
        return sum;
    }
};