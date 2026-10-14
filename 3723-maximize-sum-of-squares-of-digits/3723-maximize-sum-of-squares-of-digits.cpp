class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
    
        while(res.size()<num){
            int x=min(9,sum);
            sum-=x;
            res+=to_string(x);
        }
        if(sum!=0)return "";
        return res;
    }
};