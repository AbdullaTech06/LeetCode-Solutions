class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int mx=0;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
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
};