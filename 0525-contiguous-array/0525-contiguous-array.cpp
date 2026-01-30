class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> firstIndex;
        firstIndex[0]=-1;
        int temp=0;
        int ans=0;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1){
                temp++;
            }else{
                temp--;
            }
            if(firstIndex.count(temp)){
                ans=max(ans,i-firstIndex[temp]);
            }else{
                firstIndex[temp] = i;
            }
        }
        return ans;
    }
};
