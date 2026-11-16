
class Solution {
public:
    string digitSum(string s, int k) {
        string t=s;
        while(t.size()>k){
            string y="";
            int sum=0;
            int x=k;
            for(int i=0;i<t.size();i++){
                sum+=t[i]-'0';
                x--;
                if(x==0 || i==t.size()-1){
                    y+=to_string(sum);
                    sum=0;
                    x=k;
                }
            }
            t=y;
        }
        return t;
    }
};
