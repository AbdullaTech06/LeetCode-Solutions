class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> left(n, INF);
        vector<int> right(n, INF);

        int sum = 0;
        int l = 0;
        int best = INF;

        for (int r = 0; r < n; r++) {
            sum += arr[r];

            while (sum > target) {
                sum -= arr[l++];
            }

            if (sum == target) {
                int len = r - l + 1;
                best = min(best, len);
            }

            left[r] = best;
        }

        sum = 0;
        int r = n - 1;
        best = INF;

        for (int l = n - 1; l >= 0; l--) {
            sum += arr[l];

            while (sum > target) {
                sum -= arr[r--];
            }

            if (sum == target) {
                int len = r - l + 1;
                best = min(best, len);
            }

            right[l] = best;
        }

        int ans = INF;

        for (int i = 0; i < n - 1; i++) {
            if (left[i] != INF && right[i + 1] != INF) {
                ans = min(ans, left[i] + right[i + 1]);
            }
        }

        return ans == INF ? -1 : ans;
    }
};