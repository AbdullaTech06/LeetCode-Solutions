class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto it:m){
            v.push_back(it.second);
        }
        unordered_set<int> s;
        for(int i=0;i<v.size();i++){
            s.insert(v[i]);
        }
        return v.size()==s.size();
    }
};