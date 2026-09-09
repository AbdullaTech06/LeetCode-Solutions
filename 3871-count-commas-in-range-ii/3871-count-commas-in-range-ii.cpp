class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll ans = 0;
        ll st=1000;
        ll c=1;

        while(st<=n){
            long long end=min(n, st*1000-1);
            ans+=(end-st+1)*c;
            st*=1000;
            c++;
        }
        return ans;
    }
};