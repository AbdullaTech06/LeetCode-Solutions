class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n%2==1)return false;
        int tar=n/2;
        int a=0,b=1;
        while(b<tar){
            int c=a+b;
            a=b;
            b=c;
        }
        return b==tar;
    }
};