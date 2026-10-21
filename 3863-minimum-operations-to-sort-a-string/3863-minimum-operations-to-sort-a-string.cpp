class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(is_sorted(s.begin(),s.end()))return 0;
        if(n==2)return -1;
        char mx=*max_element(s.begin(),s.end());
        char mn=*min_element(s.begin(),s.end());
        if(mn==s[0])return 1;
        if(mx==s[n-1])return 1;

        char mxmid=*max_element(s.begin()+1,s.end()-1);
        char mnmid=*min_element(s.begin()+1,s.end()-1);

        if(s[0]>mxmid && s[n-1]<mnmid)return 3;

        return 2;
    }
};