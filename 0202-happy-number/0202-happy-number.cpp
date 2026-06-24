class Solution {
public:
    int sumofsq(int a){
        int sum=0;
        while(a>0){
            sum+=pow(a%10,2);
            a/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1 && !s.count(n)){
            s.insert(n);
            n= sumofsq(n);
        }
        return n==1;
    }
};