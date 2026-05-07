class Solution {
public:
    void solve(int idx,string& digits,string curr,vector<string>& m,vector<string>& ans){
        if(idx==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters=m[digits[idx]-'0'];
        for(char ch : letters){
            solve(idx+1,digits,curr+ch,m,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> ans;
        vector<string> m(10);
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";

        solve(0,digits,"",m,ans);
        return ans;
    }
};