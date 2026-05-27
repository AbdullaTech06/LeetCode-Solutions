class Solution {
public:
    bool islowercase(char ch){
        return ch>='a' && ch<='z';
    }
    int numberOfSpecialChars(string word) {
        vector<int> lastlower(26,-1);
        vector<int> firstupper(26,-1);
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(islowercase(ch)){
                lastlower[ch-'a']=i;
            }else{
                if(firstupper[ch-'A']==-1)firstupper[ch-'A']=i;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(lastlower[i]!=-1 && firstupper[i]!=-1 && lastlower[i]<firstupper[i]){
                ans++;
            }
        }
        return ans;
    }
};