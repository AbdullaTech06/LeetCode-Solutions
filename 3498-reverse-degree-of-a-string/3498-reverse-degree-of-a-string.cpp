class Solution {
public:
    int reverseDegree(string s) {
        char ch='a';
        unordered_map<char,int> m;
        for(int i=0;i<26;i++){
            m[ch]=26-i;
            ch++;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=(i+1)*m[s[i]];
        }
        return ans;
    }
};