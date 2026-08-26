class Solution {
public:
    bool isbeautiful(string& s,int l,int r,int k){
        int cnt=0;
        for(int i=l;i<=r;i++){
            if(s[i]=='1')cnt++;
        }
        return cnt==k;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            int o=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1')o++;
                if(o==k)len=min(len,j-i+1);
            }
        }
        int i=0;
        int j=len-1;
        vector<string> v;
        while(j<n){
            if(isbeautiful(s,i,j,k))v.push_back(s.substr(i,j-i+1));
            i++;
            j++;
        }
        sort(v.begin(),v.end());
        if(v.empty())return "";
        return v[0];
    }
};