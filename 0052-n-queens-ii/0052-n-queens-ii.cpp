class Solution {
public:
int ans=0;
    bool issafe(vector<string>& board,int row,int col,int n){
    //horizontal
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q')
        return false;
    }
    //vecrticla
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q')
        return false;
    }
    //left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
         if(board[i][j]=='Q')
        return false;
    }
    //right diagonal
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q')
        return false;
   }
   return true;
   }


    void solve(vector<string> &board,int row,int n){
        if(row==n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j]='Q';
                solve(board,row+1,n);
                board[row][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
    }
};