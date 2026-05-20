class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> seenA(n+1,0);
        vector<int> seenB(n+1,0);
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            seenA[A[i]]=1;
            if(seenB[A[i]])cnt++;
            seenB[B[i]]=1;
            if(seenA[B[i]])cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};