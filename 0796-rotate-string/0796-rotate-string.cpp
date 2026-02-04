class Solution {
public:
    bool rotateString(string s, string goal) {
        int cnt=0;
        int n=s.size();
        int m=goal.size();
        if(s==goal){
            return true;
        }
        if(n!=m){
            return false;
        }
        while(cnt<n){
            char first=s[0];
            for(int i=0;i<n-1;i++){
                s[i]=s[i+1];
            }
            s[n-1]=first;
            cnt++;
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};