class Solution {
public:
    bool ispal(string &s, int i, int j) {
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        bool used =false;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                if(!used){
                    used=true;
                    return (ispal(s,i+1,j) || ispal(s,i,j-1));
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};