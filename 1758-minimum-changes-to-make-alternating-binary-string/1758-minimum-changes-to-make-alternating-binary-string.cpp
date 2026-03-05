class Solution {
public:
    int minOperations(string s) {
        int ops1 =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0' && i%2==0){
                ops1++;
            }else if(s[i]=='1' && i%2==1){
                ops1++;
            }
        }
        int ops2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' && i%2==0){
                ops2++;
            }else if(s[i]=='0' && i%2==1){
                ops2++;
            }
        }
        return min(ops1,ops2);
    }
};