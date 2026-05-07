class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorsum=0;
        for(int it: nums){
            xorsum^=it;
        }
        int x = (xorsum&(xorsum-1))^xorsum;
        int a=0,b=0;
        for(int it : nums){
            if((it&x)==x)a^=it;
            else b^=it;
        }
        return {a,b};
    }
};