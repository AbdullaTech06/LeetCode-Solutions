class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        int n=nums.size();

        for(int val : nums){
            int digit=0;
            int temp=val;
            while(temp>0){
                temp=temp/10;
                digit++;
            }
            if(digit%2==0){
                count++;
            }
        }
        return count;
    }
};