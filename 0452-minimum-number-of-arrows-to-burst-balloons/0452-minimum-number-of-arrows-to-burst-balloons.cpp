class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int ans=0;
        int arrow=0;
        for(int i=0;i<points.size();i++){
            if(ans==0 || points[i][0]>arrow){
                ans++;
                arrow = points[i][1];
            }
        }
        return ans;
    }
};