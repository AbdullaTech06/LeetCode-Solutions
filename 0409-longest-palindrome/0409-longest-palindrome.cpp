class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int ans =0;
        for(char ch : s){
            if(st.count(ch)==0){
                st.insert(ch);
            }else{
                st.erase(ch);
                ans+=2;
            }
        }
        if(!st.empty()){
            ans+=1;
        }
        return ans;
    }
};