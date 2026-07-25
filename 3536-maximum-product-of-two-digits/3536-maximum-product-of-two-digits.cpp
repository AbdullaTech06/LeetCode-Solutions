class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        while(n>0){
            v.push_back(n%10);
            n/=10;
        }
        int sz=v.size();
        sort(v.begin(),v.end());
        return v[sz-1]*v[sz-2];
    }
};