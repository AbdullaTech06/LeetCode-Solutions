class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char> s;
        for(auto it:word){
            s.insert(it);
        }
        int n=word.size();
        int ans=0;
        while(n>8){
            ans+=n;
            n-=8;
        }
        return ans+n;
    }
};