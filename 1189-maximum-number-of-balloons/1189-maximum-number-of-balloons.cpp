class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(auto it:text){
            m[it]++;
        }
        int ans=0;
        while(1){
            if(m['b']>=1 && m['a']>=1 && m['l']>=2 && m['o']>=2 && m['n']>=1){
                ans++;
                m['b']-=1;
                m['a']-=1;
                m['l']-=2;
                m['o']-=2;
                m['n']-=1;
            }else{
                break;
            }
        }
        return ans;
    }
};