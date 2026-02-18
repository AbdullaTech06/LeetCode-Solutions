class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> bin;
        while(n>0){
            int rem = n%2;
            bin.push_back(rem);
            n/=2;
        }
        bool diff = true;
        for(int i=0;i<bin.size()-1;i++){
            if(bin[i]==bin[i+1]){
                diff=false;
            }
        }
        return diff;
    }
};