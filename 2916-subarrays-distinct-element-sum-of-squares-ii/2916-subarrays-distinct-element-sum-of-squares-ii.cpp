//chapa
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum_d = 0;
        long long sum_sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void push(int node, int start, int end) {
        if (tree[node].lazy == 0) return;

        long long val = tree[node].lazy;
        int mid = start + (end - start) / 2;
        int left_len = mid - start + 1;
        int right_len = end - mid;

        int lc = 2 * node, rc = 2 * node + 1;

        // Apply to left child
        tree[lc].sum_sq = (tree[lc].sum_sq + 2 * val * tree[lc].sum_d + val * val % MOD * left_len) % MOD;
        tree[lc].sum_d = (tree[lc].sum_d + val * left_len) % MOD;
        tree[lc].lazy = (tree[lc].lazy + val) % MOD;

        // Apply to right child
        tree[rc].sum_sq = (tree[rc].sum_sq + 2 * val * tree[rc].sum_d + val * val % MOD * right_len) % MOD;
        tree[rc].sum_d = (tree[rc].sum_d + val * right_len) % MOD;
        tree[rc].lazy = (tree[rc].lazy + val) % MOD;

        tree[node].lazy = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (l <= start && end <= r) {
            int len = end - start + 1;
            tree[node].sum_sq = (tree[node].sum_sq + 2 * val * tree[node].sum_d + val * val % MOD * len) % MOD;
            tree[node].sum_d = (tree[node].sum_d + val * len) % MOD;
            tree[node].lazy = (tree[node].lazy + val) % MOD;
            return;
        }

        push(node, start, end);
        int mid = start + (end - start) / 2;
        if (l <= mid) update(2 * node, start, mid, l, r, val);
        if (r > mid) update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
        tree[node].sum_d = (tree[2 * node].sum_d + tree[2 * node + 1].sum_d) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> last_pos;

        long long total_sum = 0;

        for (int j = 0; j < n; ++j) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;

            // Range add +1 to indices [prev + 1, j]
            update(1, 0, n - 1, prev + 1, j, 1);

            // Add total sum of squares for current end position j
            total_sum = (total_sum + tree[1].sum_sq) % MOD;

            last_pos[nums[j]] = j;
        }

        return (total_sum + MOD) % MOD;
    }
};