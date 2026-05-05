class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> st;

        for(int i=nums2.size()-1;i>=0;i--){
            int num=nums2[i];
            while(!st.empty() && st.top()<=num){
                st.pop();
            }
            m[num]=st.empty()?-1:st.top();
            st.push(num);
        }
        vector<int> ans;
        for(int x:nums1){
            ans.push_back(m[x]);
        }
        return ans;
    }
};