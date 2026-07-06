class Solution {
public:
    bool check(vector<int>& interval1,vector<int>& interval2){
        int a=interval1[0];
        int b=interval1[1];
        int c=interval2[0];
        int d=interval2[1];
        return (a<=c && d<=b);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto&a,auto&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=intervals.size();
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(!check(result.back(),intervals[i])){
                result.push_back(intervals[i]);
            }
        }
        return result.size();
    }
};