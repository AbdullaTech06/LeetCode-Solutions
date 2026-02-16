class Solution {
public:
    bool isPowerOfThree(int n) {
        long long int x=1;
        while(x<=n){
            if(n==x){
                return true;
            }
            x*=3;
        }
        return false;
    }
};