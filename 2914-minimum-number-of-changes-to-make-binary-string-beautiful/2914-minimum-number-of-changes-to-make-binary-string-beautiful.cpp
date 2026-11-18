class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]!=s[i+1])ans++;
            }
        }
        return ans;
    }
};