class Solution {
public:
    bool isvowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int maxVowels(string s, int k) {
        int cnt=0;
        int ans=0;
        int l=0;
        int n=s.size();
        for(int r=0;r<n;r++){
            if(isvowel(s[r]))cnt++;
            while(r-l+1>k){
                if(isvowel(s[l])){
                    cnt--;
                }
                l++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};