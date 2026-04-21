class Solution {
public:
        bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets=0;
        int count=0;
        for (int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i]<=day) {
                count++;
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }else{
                count=0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay,int m,int k) {
        int mxdays = *max_element(bloomDay.begin(),bloomDay.end());
        int mndays = *min_element(bloomDay.begin(),bloomDay.end());
        if((long long)m * k > bloomDay.size()){
            return -1;
        }
        int st = mndays;
        int end = mxdays;
        int ans=-1;
        while(st<=end){
            int mid = st+(end-st)/2; 

            if(canMake(bloomDay,m,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};