class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int totalOnes = 0;
        vector<pair<char, int>> blocks;
        
        for(int i=0;i<n;){
            int j=i;
            while(j<n && s[j]==s[i]){
                j++;
            }
            int len=j-i;
            if(s[i] == '1'){
                totalOnes+=len;
            }
            blocks.push_back({s[i], len});
            i=j;
        }

        int maxGain=0;
        for(int i=1;i<blocks.size()-1;i++) {
            if(blocks[i].first=='1' && blocks[i - 1].first=='0' && blocks[i + 1].first =='0') {
                int gain = blocks[i - 1].second + blocks[i + 1].second;
                maxGain = max(maxGain, gain);
            }
        }
        return totalOnes+maxGain;
    }
};