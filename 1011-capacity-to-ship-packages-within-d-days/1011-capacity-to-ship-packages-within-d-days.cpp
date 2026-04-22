class Solution {
public:
    int noofDays(vector<int>& weights,int cap){
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                days++;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int st=*max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(noofDays(weights,mid)<=days){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};