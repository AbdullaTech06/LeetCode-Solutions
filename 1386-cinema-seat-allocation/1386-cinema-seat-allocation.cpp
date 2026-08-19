class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        unordered_map<int, set<int>> mp;

        for(auto &x:a){
            mp[x[0]].insert(x[1]);
        }
        int ans=2*n;

        for(auto &it:mp){
            int row = it.first;
            set<int> &s = it.second;
            ans-=2;

            bool l = !s.count(2) && !s.count(3) && !s.count(4) && !s.count(5);

            bool m = !s.count(4) && !s.count(5) && !s.count(6) && !s.count(7);

            bool r = !s.count(6) && !s.count(7) && !s.count(8) && !s.count(9);

            if (l && r)ans += 2;
            else if (l || m || r)ans += 1;
        }
        return ans;
    }
};