class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1;
        bool x=true;
        unordered_map<int,int> m;
        for(int it:nums){
            m[it]++;
        }
        for(int i=1;i<n;i++){
            if(m[i]!=1)x=false;
        }
        if(m[n]!=2)x=false;

        return x;
    }
};