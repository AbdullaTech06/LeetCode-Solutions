class Solution {
public:
    const long long MOD=1e9+7;

    long long power(long long base,long long exp){
        long long ans=1;
            while(exp>0){
            if(exp%2==1){
                ans=(ans*base)%MOD;
            }
            base=(base*base)%MOD;
            exp/=2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long evenpos= (n+1)/2;
        long long oddpos=n/2;

        long long eways=power(5,evenpos);
        long long oways=power(4,oddpos);

        return (eways*oways)%MOD;
    }
};