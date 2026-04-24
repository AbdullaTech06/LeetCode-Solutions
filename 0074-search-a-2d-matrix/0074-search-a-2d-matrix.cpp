class Solution {
public:

    bool binarysearch(vector<vector<int>>mat,int target,int midr){
        int n = mat[0].size();
        int st=0,end=n-1;

        while(st<=end){
            int mid = st+(end-st)/2;
            if(mat[midr][mid]==target){
                return true;
            }else if(mat[midr][mid]>target){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        int str=0,endr=m-1;
        while(str<=endr){
          int midr = str+(endr-str)/2;
            
            if(target>=mat[midr][0] && target<=mat[midr][n-1]){
                return binarysearch(mat,target,midr);
            }else if(target<mat[midr][0]){
                endr = midr-1;
            }else{
                str = midr+1;
            }
        }
        return false;     
   }
};