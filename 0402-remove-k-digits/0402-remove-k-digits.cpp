class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char ch : num){
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.size() && s[i]=='0'){
            i++;
        }
        s=s.substr(i);
        if(s.empty())return "0";
        return s;
    }
};