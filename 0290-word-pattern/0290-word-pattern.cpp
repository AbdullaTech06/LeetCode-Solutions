
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> rev;
        int idx=0;
        int n=s.size();

        for(int i=0;i<pattern.size();i++){
            if(idx>=n)return false;

            string word="";
            while(idx<n && s[idx]!=' '){
                word+=s[idx];
                idx++;
            }
            char ch=pattern[i];

            if(mp.find(ch)!=mp.end()){
                if(mp[ch]!=word)return false;
            }else{
                if(rev.find(word)!=rev.end())return false;
                mp[ch]=word;
                rev[word]=ch;
            }
            if(idx<n)idx++;
        }
        return idx==n && pattern.size()>0;
    }
};
