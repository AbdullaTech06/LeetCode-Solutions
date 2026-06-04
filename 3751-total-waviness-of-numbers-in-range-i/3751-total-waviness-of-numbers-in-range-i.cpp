class Solution {
public:
    int peaks(int x){
        string s=to_string(x);
        int cnt=0;
        for(int i=1;i<s.size()-1;i++){
            if(s[i-1]<s[i] && s[i]>s[i+1])cnt++;
        }
        return cnt;
    }

    int valley(int x){
        string s=to_string(x);
        int cnt=0;
        for(int i=1;i<s.size()-1;i++){
            if(s[i-1]>s[i] && s[i]<s[i+1])cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=peaks(i)+valley(i);
        }
        return ans;
    }
};