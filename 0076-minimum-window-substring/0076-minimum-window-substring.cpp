class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(char ch:t){
            m[ch]++;
        }
        int l=0;
        int req=t.size();
        int mn=INT_MAX;
        int st=0;
        for(int r=0;r<s.size();r++){
            if(m[s[r]]>0)req--;
            m[s[r]]--;
            while(req==0){
                if(r-l+1<mn){
                    mn=r-l+1;
                    st=l;
                }
                m[s[l]]++;
                if(m[s[l]]>0)req++;

                l++;
            }
        }
        return mn==INT_MAX?"":s.substr(st,mn);
    }
};