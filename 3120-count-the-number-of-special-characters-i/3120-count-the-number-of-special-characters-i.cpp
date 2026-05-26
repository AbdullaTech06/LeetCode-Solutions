class Solution {
public:
    bool islowercase(char ch){
        return ch>='a' && ch<='z';
    }
    bool isuppercase(char ch){
        return ch>='A' && ch<='Z';
    }
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(),word.end());
        int cnt=0;
        for(char ch:s){
            if(islowercase(ch)){
                if(s.count(ch-32))cnt++;
            }
        }
        return cnt;
    }
};