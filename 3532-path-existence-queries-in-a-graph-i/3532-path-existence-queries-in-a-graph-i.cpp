class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> cmp(n,-1);
        int cmpid=0;
        cmp[0]=cmpid;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                cmpid++;
            }
            cmp[i]=cmpid;
        }
        vector<bool> ans;
        for(auto it:queries){
            ans.push_back(cmp[it[0]]==cmp[it[1]]);
        }
        return ans;
    } 
};