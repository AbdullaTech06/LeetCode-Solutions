class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(int val : nums){
            if(val>0){
                pos.push_back(val);
            }else if(val<0){
                neg.push_back(val);
            }
        }
        int idxpos=0;
        int idxneg=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=pos[idxpos];
                idxpos++;
            }else{
                nums[i]=neg[idxneg];
                idxneg++;
            }
        }
        return nums;
    }
};