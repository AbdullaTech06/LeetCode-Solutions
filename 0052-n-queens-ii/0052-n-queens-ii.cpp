class Solution {
public:
int ans=0;
    bool issafe(vector<string>& board, int row, int col, int n) {
        // check upper column
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
                return false;
        }
        // upper-left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
        // upper-right diagonal
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j] =='Q')
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