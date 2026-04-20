class Solution {
public:
    long long calcluatetotalhours(vector<int>& piles,int hourly){
        long long totalh =0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            totalh += (piles[i] + hourly - 1) / hourly;
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mxel = *max_element(piles.begin(),piles.end());
        int st = 1;
        int end = mxel;
        while(st<=end){
            int mid = st+(end-st)/2;
            long long totalh = calcluatetotalhours(piles,mid);
            if(totalh<=h){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;
    }
};