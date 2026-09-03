class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int o=0;
        int e=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0)e++;
            else o++;
        }
        if(o==0 || e==0)return true;
        vector<int> odd,even;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0)even.push_back(nums1[i]);
            else odd.push_back(nums1[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());

        bool x=true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                if(nums1[i]-odd[0]<=0){
                    x=false;
                    break;
                }        
            }
        }
        return x;
    }
};