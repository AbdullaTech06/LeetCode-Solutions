class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<int> R(m + 1, -1);
        R[m]=n;

        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                R[j]=i;
                i--;
                j--;
            }else{
                i--;
            }
        }

        vector<int> res;
        res.reserve(m);
        bool used=false;
        i=0;
        j=0;
        while(j<m && i<n){
            if(word1[i]==word2[j]){
                res.push_back(i);
                i++;
                j++;
            }else if(!used && i+1<=R[j+1]){
                res.push_back(i);
                used = true;
                i++;
                j++;
            }else{
                i++;
            }
        }
        return (int)res.size()==m?res:vector<int>{};
    }
};