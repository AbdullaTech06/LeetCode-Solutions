class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int temp=n;
        int x=1;
        int oddsum=0;
        while(temp--){
            oddsum+=x;
            x+=2;
        }
        temp=n;
        int y=2;
        int evensum=0;
        while(temp--){
            evensum+=y;
            y+=2;
        }
        return __gcd(evensum,oddsum);
    }
};