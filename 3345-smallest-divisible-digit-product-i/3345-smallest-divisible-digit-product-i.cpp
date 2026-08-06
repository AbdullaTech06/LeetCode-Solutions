class Solution {
public:
    int prd(int x){
        int p=1;
        while(x>0){
            p*=(x%10);
            x/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        int x=n;
        while(1){
            if(prd(x)%t==0)return x;
            x++;
        }
        return -1;
    }
};