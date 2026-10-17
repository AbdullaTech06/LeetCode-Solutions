class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> o,e;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                e.push_back(nums[i]);
            }else{
                o.push_back(nums[i]);
            }
        }
        sort(o.rbegin(),o.rend());
        sort(e.begin(),e.end());
        vector<int> res;
        int i=0;
        int j=0;
        while(res.size()<n && i<e.size() && j<o.size()){
            res.push_back(e[i++]);
            res.push_back(o[j++]);
        }
        while(i<e.size()){
            res.push_back(e[i++]);
        }
        while(j<o.size()){
            res.push_back(o[j++]);
        }
        return res;
    }
};