class Solution {
public:
    bool pun(int num,int sum,int tar){
        if(num==0)return sum==tar;

        int cur=0;
        int place=1;
        int temp=num;
        while(temp>0){
            cur=(temp%10)*place+cur;
            if(sum+cur<=tar){
                if(pun(temp/10,sum+cur,tar))return true;
            }
            place*=10;
            temp/=10;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            if(pun(sq,0,i))ans+=sq;
        }
        return ans;
    }
};