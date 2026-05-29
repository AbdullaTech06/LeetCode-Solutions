class Solution {
public:
    void dfs(vector<vector<int>> &ans,int inicolor,int color,int r,int c){
        int n=ans.size();
        int m=ans[0].size();
        if(r<0 || c<0 || r>=n || c>=m){
            return;
        }
        if(ans[r][c]!=inicolor || ans[r][c]==color){
            return;
        }
        ans[r][c]=color;
        dfs(ans,inicolor,color,r-1,c);
        dfs(ans,inicolor,color,r+1,c);
        dfs(ans,inicolor,color,r,c-1);
        dfs(ans,inicolor,color,r,c+1);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int inicolor=image[sr][sc];
        if(inicolor==color){
            return image;
        }
        dfs(ans,inicolor,color,sr,sc);
        return ans;
    }
};