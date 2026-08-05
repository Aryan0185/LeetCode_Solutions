class Solution {
public: 
    bool isvalid(vector<vector<char>>& board,char ch,int row,int col ){
        for(int j=0;j<9;j++){
            if(board[row][j]==ch)return false;
        }
         for(int i=0;i<9;i++){
            if(board[i][col]==ch)return false;
        }
        int startrow=(row/3)*3;
        int startcol=(col/3)*3;
        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(board[i][j]==ch)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isvalid(board,ch,i,j)){
                          board[i][j]=ch;
                          if(solve(board))return true;
                          board[i][j]='.';
                        }
                    }
                     return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};