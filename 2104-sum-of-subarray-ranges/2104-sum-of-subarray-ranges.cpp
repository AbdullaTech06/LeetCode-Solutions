class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftmin(n),rightmin(n);
        vector<int> leftmax(n),rightmax(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i])st.pop();
            if(st.empty())leftmin[i]=i+1;
            else leftmin[i]=i-st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
            if(st.empty())rightmin[i]=n-i;
            else rightmin[i]=st.top()-i;
            st.push(i);
        }
        while(!st.empty())st.pop();


        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i])st.pop();
            if(st.empty())leftmax[i]=i+1;
            else leftmax[i]=i-st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            if(st.empty())rightmax[i]=n-i;
            else rightmax[i]=st.top()-i;
            st.push(i);
        }

        long long minsum=0;
        long long maxsum=0;
        for(int i=0;i<n;i++){
            minsum+=1LL*nums[i]*leftmin[i]*rightmin[i];
            maxsum+=1LL*nums[i]*leftmax[i]*rightmax[i];
        }
        return maxsum-minsum;
    }
};