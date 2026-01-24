class Solution {
public:
    int countdigits(int n){
        if(n == 0) return 1;
        int digits=0;
        while(n>0){
            n/=10;
            digits++;
        }
        return digits;
    } 
    int addDigits(int num) {
        int n=num;
        while(countdigits(n)!=1){
            int sum = 0;
            while(n>0){
                int rem = n%10;
                sum+=rem;
                n/=10;
            }
            n=sum;
        }
        return n;
    }
};