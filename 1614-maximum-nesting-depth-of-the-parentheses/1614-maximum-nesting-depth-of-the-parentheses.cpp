class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans =0;
        for(char ch : s){
            if(ch=='('){
                st.push('(');
                ans = max(ans,(int)st.size());
            }else if(ch==')'){
                st.pop();
            }
        }
        return ans;

    }
};