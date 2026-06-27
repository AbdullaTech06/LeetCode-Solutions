class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> m;
        for(auto it: nums){
            m[it]++;
        }
        vector<int> v;
        for(auto it:m){
            v.push_back(it.first);
        }
        sort(v.begin(),v.end());
        int ans=INT_MIN;

        if(m.count(1)){
            int countOnes=m[1];
            if(countOnes%2==0){
                ans=max(ans,countOnes-1);
            }else{
                ans=max(ans,countOnes);
            }
        }

        for(int i=0;i<v.size();i++){
            int cnt=0;
            long long x=v[i];
            if(x==1)continue;
            while(1){
                if(m[x]>=2 && m[x*x]>=1){
                    cnt+=2;
                }else if(m[x]>=1){
                    cnt++;
                    break;
                }else break;
                x*=x;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};