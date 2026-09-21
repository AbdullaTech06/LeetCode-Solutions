class Solution {
public:
    typedef long long ll;
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll>res(k,0);
        vector<ll>prevcnt(k,0);

        for(int i=0;i<n;i++){
            vector<ll>curcnt(k,0);
            int curelrem=nums[i]%k;
            curcnt[curelrem]++;
            for(int oldr=0;oldr<k;oldr++){
                int newr=((ll)oldr*nums[i]%k)%k;
                curcnt[newr]+=prevcnt[oldr];
            }
            prevcnt=move(curcnt);
            for(int x=0;x<k;x++){
                res[x]+=prevcnt[x];
            }
        }
        return res;
    }
};