
class Solution {
public:
    typedef long long ll;
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            ll p=1;
            ll g=0;
            ll l=1;

            for(int j=i;j<n;j++){
                p*=nums[j];
                g=gcd(g,(ll)nums[j]);
                l=l/gcd(l,(ll)nums[j])*nums[j];
                if(p==g*l){
                    ans=max(ans,j-i+1);
                }
                if(p>g*l)break;
            }
        }
        return ans;
    }
};
