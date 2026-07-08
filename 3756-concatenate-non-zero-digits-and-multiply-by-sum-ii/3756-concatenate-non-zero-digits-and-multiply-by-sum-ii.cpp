class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> nonzerocount(n,0);
        vector<ll> numberupto(n,0);
        vector<ll> sumupto(n,0);
        vector<ll> pow10(n+1,0);

        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%mod;
        }

        nonzerocount[0]=(s[0]!='0')?1:0;
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            nonzerocount[i]=nonzerocount[i-1]+((digit!=0)?1:0);
        }

        numberupto[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                numberupto[i]=((numberupto[i-1]*10)+digit)%mod;
            }else{
                numberupto[i]=numberupto[i-1];
            }
        }

        sumupto[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            sumupto[i]=sumupto[i-1]+digit;
        }

        int q=queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            int stcnt=(l==0)?0:nonzerocount[l-1];
            ll numbefore=(l==0)?0:numberupto[l-1];

            int endcnt=nonzerocount[r];
            int substrlen=endcnt-stcnt;

            if(substrlen==0){
                ans[i]=0;
                continue;
            }
            ll x=(numberupto[r]-(numbefore*pow10[substrlen]%mod)+mod)%mod;
            ll sum=sumupto[r]-(l==0?0:sumupto[l-1]);

            ans[i]=(int)((x*sum)%mod);
        }
        return ans;
    }
};