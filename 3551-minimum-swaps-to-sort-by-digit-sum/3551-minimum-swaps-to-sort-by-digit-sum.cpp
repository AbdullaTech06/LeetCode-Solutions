class Solution {
public:
    static int dsum(int a){
        int res=0;
        while(a>0){
            res+=a%10;
            a/=10;
        }
        return res;
    }
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(dsum(a.first)==dsum(b.first))return a.first<b.first;
        return dsum(a.first)<dsum(b.first);
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> vis(n,0);
        int cycles=0;
        for(int i=0;i<nums.size();i++){
            if(vis[i])continue;
            cycles++;
            int j=i;
            while(!vis[j]){
                vis[j]=1;
                j=v[j].second;
            }
        }
        return n-cycles;
    }
};