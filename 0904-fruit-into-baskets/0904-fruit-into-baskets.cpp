class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0;
        int ans=0;
        unordered_map<int,int> m;
        for(int r=0;r<n;r++){
            m[fruits[r]]++;
            while(m.size()>2 && l<r){
                m[fruits[l]]--;
                if(m[fruits[l]]==0)m.erase(fruits[l]);
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};