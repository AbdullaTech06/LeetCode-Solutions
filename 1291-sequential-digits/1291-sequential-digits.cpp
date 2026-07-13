class Solution {
public:
    int lenof(int x){
        int sz=0;
        while(x>0){
            sz++;
            x/=10;
        }
        return sz;
    }
    int generate(int size,int digit,int num){
        if(lenof(num)==size)return num;
        if(digit>=10)return -1;
        num=num*10+digit;
        return generate(size,digit+1,num);
    }
    vector<int> sequentialDigits(int low, int high) {
        int lowsize=0;
        int temp=low;
        while(temp>0){
            lowsize++;
            temp/=10;
        }
        temp=high;
        int highsize=0;
        while(temp>0){
            highsize++;
            temp/=10;
        }
        vector<int> ans;
        for(int i=lowsize;i<=highsize;i++){
            int size=i;
            for(int st=1;st<=9;st++){
                int num=generate(size,st,0);
                if(num<low)continue;
                if(num>high)continue;
                if(num!=-1)ans.push_back(num);
            }
        }
        return ans;
    }
};