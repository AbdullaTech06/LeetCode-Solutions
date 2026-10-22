class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int acnt=0;
        int dcnt=0;
        for(int i=1;i<n;i++){
            acnt+=(nums[i]==(nums[i-1]+1)%n);
            dcnt+=(nums[i-1]==(nums[i]+1)%n);
        }
        if(acnt==n-1 && nums[0]==0)return 0;

        if(acnt==n-1){
            int leftr=n-nums[0];
            int rightr=1+(nums.back()+1)+1;
            return min(leftr,rightr);
        }

        if(dcnt==n-1){
            int leftr=n-nums.back()+1;
            int rightr=(nums[0]+1)%n+1;
            return min(leftr,rightr);
        }

        return -1;

    }
};