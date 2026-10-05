class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int score=0;
        int i=0;
        int x=0;
        while(i<n){
            if(s[i]=='('){
                x++;
            }else{
                x--;
                if(s[i-1]=='('){
                    score+=(1<<x);
                }
            }
            i++;
        }
        return score;
    }
};