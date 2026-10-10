class Solution {
public:
    typedef long long ll;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size(); 
        vector<ll> v;
        for(int i=0;i<n;i++){
            v.push_back(abs(nums1[i]-nums2[i]));
        }
        vector<int> freq(1e5+1,0);
        for(int i=0;i<n;i++){
            freq[v[i]]++;
        }
        ll ops=1LL*(k1+k2);
        for(int i=1e5;i>=1;i--){
            int cops=min(1LL*freq[i],ops);
            freq[i]-=cops;
            freq[i-1]+=cops;
            ops-=cops;
        }

        ll ans=0;
        for(int i=0;i<=1e5;i++){
            ans+=1LL*freq[i]*i*i;
        }
        return ans;
    }
};