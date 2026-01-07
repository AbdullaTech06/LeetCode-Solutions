class Solution {
public:

    bool isCapital(char ch){
        if(65<=ch && ch<=90){
            return true;
        }else{
            return false;
        }
    }
    bool detectCapitalUse(string word) {
        //all capital
        bool allcapital = true;
        for(int i=0;i<word.size();i++){
            if(!isCapital(word[i])){
                allcapital = false;
            }
        }

        //all small
        bool allsmall = true;
        for(int i=0;i<word.size();i++){
            if(isCapital(word[i])){
                allsmall=false;
            }
        }

        //firsrt capital
        bool rest_all_small = false;
        if(isCapital(word[0])){
            rest_all_small = true;
            for(int i=1;i<word.size();i++){
                if(isCapital(word[i])){
                rest_all_small=false;
            }
            }
        }

        if(allcapital || allsmall || rest_all_small){
            return true;
        }else{
            return false;
        }
    }
};