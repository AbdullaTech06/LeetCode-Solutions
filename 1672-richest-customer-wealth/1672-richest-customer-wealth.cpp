class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size();
        int n=accounts[0].size();
        int mx=INT_MIN;
        for(int i=0;i<m;i++){
            int s=0;
            for(int j=0;j<n;j++)s+=accounts[i][j];
            mx=max(mx,s);
        }
        return mx;
    }
};