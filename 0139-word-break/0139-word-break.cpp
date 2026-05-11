class Solution {
public:
    bool solve(string &s,unordered_set<string>& dict,unordered_map<int,bool>& memo,int st){
        if(st==s.size())return true;
        if(memo.count(st))return memo[st];

        for(int end=st+1;end<=s.size();end++){
            if(dict.count(s.substr(st,end-st)) && solve(s,dict,memo,end)){
                return memo[st]=true;
            }
        }
        return memo[st]=false;
    } 
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        unordered_map<int,bool>memo;
        return solve(s,dict,memo,0);
    }
};