class Solution {
public:
    bool check(string a,string b){
        unordered_set<char> s1,s2;
        for(char ch:a)s1.insert(ch);
        for(char ch:b)s2.insert(ch);

        for(char ch:a){
            if(!s2.count(ch))return false;
        }
        for(char ch:b){
            if(!s1.count(ch))return false;
        }
        return true;
    }
    int similarPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(words[i],words[j]))ans++;
            }
        }
        return ans;
    }
};