class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string first = "";
        for(int i=0;i<n/2;i++)first+=s[i];
        sort(first.begin(),first.end());
        string second=first;
        reverse(second.begin(),second.end());
        
        if(n%2==0)return first+second;
        return first+s[n/2]+second;
    }
};