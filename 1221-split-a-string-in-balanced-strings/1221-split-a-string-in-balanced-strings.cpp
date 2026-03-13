class Solution {
public:
    int balancedStringSplit(string s) {
        int x=0;
        int ans=0;
        for(char ch : s){
            if(ch=='R'){
                x++;
            }else{
                x--;
            }
            if(x==0){
                ans++;
            }
        }
        return ans;
    }
};