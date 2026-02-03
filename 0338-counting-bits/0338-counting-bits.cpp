class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int num=i;
            int cnt=0;
            while(num!=0){
                cnt+=num%2;
                num/=2;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};