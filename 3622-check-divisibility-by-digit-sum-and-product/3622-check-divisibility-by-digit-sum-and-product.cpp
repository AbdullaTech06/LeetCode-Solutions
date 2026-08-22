class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int x=n;
        while(x>0){
            sum+=x%10;
            prod*=x%10;
            x/=10;
        }
        int d=sum+prod;
        return n%d==0;
    }
};