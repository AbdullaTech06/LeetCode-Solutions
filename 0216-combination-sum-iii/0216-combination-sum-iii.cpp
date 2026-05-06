class Solution {
public:
    void solve(int x,int tar,int curr,vector<int>& temp,vector<vector<int>>& ans){
        if(tar==0 && x==0){
            ans.push_back(temp);
            return;
        }
        if(curr>9 || tar<0 || x<0){
            return;
        }
        if(tar<curr){
            return;
        }

        temp.push_back(curr);
        solve(x-1,tar-curr,curr+1,temp,ans);
        temp.pop_back();
        solve(x,tar,curr+1,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k,n,1,temp,ans);
        return ans;
    }
};