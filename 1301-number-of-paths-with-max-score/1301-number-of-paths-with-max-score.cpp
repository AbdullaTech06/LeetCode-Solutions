class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> t;
    int mod=1e9+7;

    int chartoint(char ch){
        if(ch=='S'||ch=='E')return 0;
        return ch-'0';
    }

    bool isvalid(int i,int j,vector<string>& board){
        return i>=0 && i<n && j>=0 && j<n && board[i][j]!='X';
    }

    pair<int,int> solve(int i,int j,vector<string>& board){
        if(board[i][j]=='E')return{0,1};
        if(board[i][j]=='X')return {0,0};
        if(t[i][j]!=make_pair(-1,-1))return t[i][j];

        int upscore=0,uppaths=0;
        int leftscore=0,leftpaths=0;
        int diagscore=0,diagpaths=0;
        char ch=board[i][j];

        //up
        if(isvalid(i-1,j,board)){
            auto [score,paths]=solve(i-1,j,board);
            upscore=score;
            uppaths=paths;
            if(uppaths>0)upscore+=chartoint(ch);
        }
        //left
        if(isvalid(i,j-1,board)){
            auto[score,paths]=solve(i,j-1,board);
            leftscore=score;
            leftpaths=paths;
            if(leftpaths>0)leftscore+=chartoint(ch);
        }
        //diag
        if(isvalid(i-1,j-1,board)){
            auto[score,paths]=solve(i-1,j-1,board);
            diagscore=score;
            diagpaths=paths;
            if(diagpaths>0)diagscore+=chartoint(ch);
        }

        int bestscore,bestpaths;
        
        if(upscore==leftscore && leftscore==diagscore){
            bestscore=upscore;
            bestpaths=uppaths+leftpaths+diagpaths;
        }else if(upscore==leftscore){
            bestscore=upscore;
            bestpaths=uppaths+leftpaths;
            if(diagscore>bestscore || (diagscore==bestscore && diagpaths>bestpaths)){
                bestscore=diagscore;
                bestpaths=diagpaths;
            }
        }else if(leftscore==diagscore){
            bestscore=leftscore;
            bestpaths=leftpaths+diagpaths;
            if(upscore>bestscore ||(bestscore==upscore && uppaths>bestpaths)){
                bestscore=upscore;
                bestpaths=uppaths;
            }
        }else{
            bestscore=upscore;
            bestpaths=uppaths;
            if(leftscore>bestscore || (leftscore==bestscore && leftpaths>bestpaths)){
                bestscore=leftscore;
                bestpaths=leftpaths;
            }
            if(diagscore>bestscore || (diagscore==bestscore && diagpaths>bestpaths)){
                bestscore=diagscore;
                bestpaths=diagpaths;
            }
        }
        return t[i][j]={bestscore,bestpaths%mod};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        t.assign(n,vector<pair<int,int>>(n,{-1,-1}));
        auto result=solve(n-1,n-1,board);

        return {result.first,result.second};
    }
};