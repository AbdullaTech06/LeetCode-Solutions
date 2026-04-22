class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(), arr.end());
        int current=1;

        while(1){
            if(s.find(current)==s.end()) {
                k--;
                if(k == 0){
                    return current;
                }
            }
            current++;
        }
    }
};