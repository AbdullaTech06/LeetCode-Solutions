class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(res.size());
                continue;
            }
            if(s[i]==')'){
                int x=st.top();
                st.pop();
                reverse(res.begin()+x,res.end());
                continue;
            }
            res+=s[i];
        }
        return res;
    }
};