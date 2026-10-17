class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int tar) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(nums[i]+nums[j]==tar && nums[i]>nums[j]){
                    v.push_back({i,j});
                }
            }
        }
        if(v.empty())return {-1,-1};
        int mx=INT_MIN;
        int mxi=-1;
        int mxj=-1;
        for(int i=0;i<v.size();i++){
            if(nums[v[i].first]*nums[v[i].second]>mx){
                mx=nums[v[i].first]*nums[v[i].second];
                mxi=v[i].first;
                mxj=v[i].second;
            }
        }
        return {mxi,mxj};
    }
};