class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>  m;
        int l=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            m[s[r]]++;
            while(m[s[r]]>2){
                m[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};