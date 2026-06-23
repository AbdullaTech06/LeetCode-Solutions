class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m), down(m), nup(m), ndown(m);

        // length = 2
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {

            long long pref = 0;
            for (int i = 0; i < m; i++) {
                nup[i] = pref;
                pref += down[i];
                if (pref >= MOD) pref %= MOD;
            }

            long long suff = 0;
            for (int i = m - 1; i >= 0; i--) {
                ndown[i] = suff;
                suff += up[i];
                if (suff >= MOD) suff %= MOD;
            }

            swap(up, nup);
            swap(down, ndown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += up[i];
            ans += down[i];
            ans %= MOD;
        }

        return ans;
    }
};