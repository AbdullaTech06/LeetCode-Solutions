class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxrow=0;
            for(int i=0;i<m;i++){
                if(mat[i][mid]>mat[maxrow][mid])maxrow=i;
            }

            int left=(mid-1>0)? mat[maxrow][mid-1]:-1;
            int right=(mid+1<n)? mat[maxrow][mid+1]:-1;

            if(mat[maxrow][mid]>left && mat[maxrow][mid]>right){
                return {maxrow,mid};
            }
            if(right>mat[maxrow][mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
};