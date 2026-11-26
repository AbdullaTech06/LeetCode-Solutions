class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return false;

        for(int i=10;i>=1;i--){
            if(n<0)return i%2==0?true:false;
            n-=i;
        }
        return true;
    }
};