class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b){
        while (b) {
            ll temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    ll lcm(ll a, ll b, ll limit) {
        ll g = gcd(a, b);
        a /= g;
        if(a > limit/b)
            return limit + 1;

        return a * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto count = [&](ll x) {
            ll cnt = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                ll curLcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        curLcm = lcm(curLcm, coins[i], x);

                        if (curLcm > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if(!valid)continue;

                if(bits%2)cnt+=x/curLcm;
                else cnt-=x/curLcm;
            }

            return cnt;
        };

        ll low = 1;
        ll high = 1LL * *min_element(coins.begin(), coins.end()) * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;
            if(count(mid)>=k)high = mid;
            else low = mid + 1;
        }
        return low;
    }
};