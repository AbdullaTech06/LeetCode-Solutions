class node {
public:
    int data;
    int row;
    int col;
    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) { return a->data > b->data; }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<node*, vector<node*>, compare> pq;
        int mn = INT_MAX;
        int mx = INT_MIN;

        for (int i = 0; i < k; i++) {
            int el = nums[i][0];
            mn = min(mn, el);
            mx = max(mx, el);
            pq.push(new node(el, i, 0));
        }
        int st = mn;
        int end = mx;

        while (!pq.empty()) {
            node* temp = pq.top();
            pq.pop();
            mn = temp->data;
            if (mx - mn < end - st) {
                st = mn;
                end = mx;
            }
            int row = temp->row;
            int col = temp->col;
            if (col + 1 < nums[row].size()) {
                int nextel = nums[row][col + 1];
                mx = max(mx, nextel);
                pq.push(new node(nextel, row, col + 1));
            } else {
                break;
            }
        }
        return {st, end};
    }
};