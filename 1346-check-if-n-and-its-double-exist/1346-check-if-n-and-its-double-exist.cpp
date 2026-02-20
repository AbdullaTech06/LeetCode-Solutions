class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(s.count(2*arr[i]) || (arr[i]%2==0 && s.count(arr[i]/2))){
                return true;
            }
            s.insert(arr[i]);
        }
        return false;
    }
};