class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        
        for(int i=0;i<s.size();i++){
            last[s[i]-'a'] = i;
        }
        
        vector<bool> used(26, false);
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            
            if(used[c-'a']) continue;
            
            while(!st.empty() && st.top() > c && last[st.top() - 'a'] > i) {
                used[st.top()-'a'] = false;
                st.pop();
            }
            
            st.push(c);
            used[c-'a'] = true;
        }
        
        string result = "";
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};