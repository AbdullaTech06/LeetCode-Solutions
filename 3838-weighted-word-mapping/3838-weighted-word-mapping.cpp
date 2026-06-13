class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        vector<char> revmap(26);
        char c='z';
        for(int i=0;i<26;i++){
            revmap[i]=c;
            c--;
        }
        string ans="";
        for(int i=0;i<n;i++){
            string word=words[i];
            int sum=0;
            for(char ch:word){
                sum+=weights[ch-'a'];
            }
            sum%=26;
            ans+=revmap[sum];
        }
        return ans;
    }
};