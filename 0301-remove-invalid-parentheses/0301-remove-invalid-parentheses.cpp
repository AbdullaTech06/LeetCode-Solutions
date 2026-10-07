class Solution {
public:
    set<string> ans;
    void solve(string &s, int i, string cur,int balance, int leftRemove, int rightRemove) {
        if (i == s.size()) {
            if(balance==0 && leftRemove==0 && rightRemove==0){
                ans.insert(cur);
            }
            return;
        }
        char ch = s[i];

        if (ch == '('){
            if (leftRemove > 0){
                solve(s, i + 1, cur, balance,
                      leftRemove - 1, rightRemove);
            }

            solve(s, i + 1, cur + ch, balance + 1,
                  leftRemove, rightRemove);
        }

        else if (ch == ')') {

            if (rightRemove > 0) {
                solve(s, i + 1, cur, balance,
                      leftRemove, rightRemove - 1);
            }

            if (balance > 0) {
                solve(s, i + 1, cur + ch, balance - 1,
                      leftRemove, rightRemove);
            }
        }else{
            solve(s, i + 1, cur + ch,
                  balance, leftRemove, rightRemove);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int leftRemove = 0;
        int rightRemove = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {

                if (balance > 0) {
                    balance--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        leftRemove = balance;

        solve(s, 0, "", 0, leftRemove, rightRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};