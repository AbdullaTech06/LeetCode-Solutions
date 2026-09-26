class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(auto&x:knowledge)mp[x[0]]=x[1];

        string ans="";

        int i=0;

        while(i<s.size()){
            if(s[i]=='('){
                i++;
                string key = "";

                while(s[i]!=')'){
                    key+=s[i];
                    i++;
                }

                if(mp.find(key)!=mp.end()){
                    ans+=mp[key];
                }else{
                    ans+="?";
                }
                i++;
            }else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};