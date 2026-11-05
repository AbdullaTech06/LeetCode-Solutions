class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            int x=arr1[i];
            bool flag=true;
            for(int j=0;j<arr2.size();j++){
                if(abs(x-arr2[j])<=d){
                    flag=false;
                    break;
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};