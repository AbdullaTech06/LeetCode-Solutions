class Solution {
public: 
    int largestRectangleArea(vector<int>& heights) {
        int y=heights.size();
        stack<int> st;
        int mx=0;

        for(int i=0;i<=y;i++){
            while(!st.empty() && (i==y || heights[st.top()]>=heights[i])){
                int height=heights[st.top()];
                st.pop();
                int r=i;
                int l;
                if(st.empty()){
                    l=-1;
                }else{
                    l=st.top();
                }
                int w=r-l-1;
                mx=max(mx,height*w);
            }
            st.push(i);
        }
        return mx;
    }
int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> heights(n, 0);
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')heights[j]++;
                else heights[j]=0;
            }
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};