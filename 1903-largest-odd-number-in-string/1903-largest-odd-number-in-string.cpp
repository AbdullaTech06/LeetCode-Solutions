class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            int digit = num[i]-'0';
            if(digit%2==1){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return "";
        }
        return num.substr(0,idx+1);
    }
};