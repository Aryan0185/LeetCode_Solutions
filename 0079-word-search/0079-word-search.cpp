class Solution {
public: 
    int rows;
    int cols;
    bool solve(int row,int col,int idx,vector<vector<char>> & board,string & word){
        if(idx==word.size())return true;
        if(row<0 || row>=rows || col<0 || col>=cols || board[row][col]!=word[idx])
        return false;
        char original=board[row][col];
        board[row][col]='#';
        bool found= solve(row+1,col,idx+1,board,word) ||
        solve(row-1,col,idx+1,board,word) ||
        solve(row,col+1,idx+1,board,word) ||
        solve(row,col-1,idx+1,board,word);
        board[row][col]=original;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
         rows=board.size();
         cols=board[0].size();
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(solve(r,c,0,board,word))return true;
            }
        }
        return false;
    }
};