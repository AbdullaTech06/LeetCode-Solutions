class Solution {
public:
    bool isvowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
    }
    string reverseVowels(string s) {
        vector<char> v;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i]))v.push_back(s[i]);
        }
        reverse(v.begin(),v.end());
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=v[idx];
                idx++;
            }
        }
        return s;
    }
};