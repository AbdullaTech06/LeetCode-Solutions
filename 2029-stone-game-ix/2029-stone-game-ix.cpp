class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int m1=0;
        int m2=0;
        int m0=0;
        for(auto it:stones){
            if(it%3==0)m0++;
            else if(it%3==1)m1++;
            else if(it%3==2)m2++;
        }
        if(m1==0 && m2==0)return false;
        
        if(m0%2==0){
            return m2>=1 && m1>=1;
        }
        return abs(m1-m2)>2;
    }
};