class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_set<char> set;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(set.count(t[i])==0){
                m[s[i]]=t[i];
            }
            set.insert(t[i]);
        }
        for(int i=0;i<n;i++){
            s[i]=m[s[i]];
        }
        if(s==t){
            return true;
        }else{
            return false;
        }
    }
};