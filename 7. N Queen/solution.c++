
class Solution {
public:

bool isSafe(int row, int col, int n, vector<string>&board){

    int r = row;
    int c = col;

    // We have to check only for three direction rest all is not required as queen only placed at right side 
    // Moving North west direction 
    while(row >= 0 and col >= 0){
        if(board[row][col]=='Q')
            return false;
        row--;
        col--;
    }

    row = r;
    col = c;

    // Moving West direction 
    while(col >= 0){
        if(board[row][col]== 'Q')
            return false;
        col--;
    }


    row = r;
    col = c;
    // Moving South west directiopn
    while(row < n and col >= 0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col --;
    }

    return true;
}

// Slove code for each iteration of n*n board 
void slove(int col, int n, vector<string>&board, vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n ; row++){
        //check if queen is on safe place 
        if(isSafe(row, col , n , board)){

            // if queen is safe then we place the queen 
            board[row][col] ='Q';

            // after placing the queen we call function to check next column 
            slove(col+1,n,board,ans);

            // after returning again remove the queen 
            board[row][col]='.';
        }
    }

}


// Base code 
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
       vector<string> board(n, string(n, '.'));

        // First we have to pass the loactiion of queen 
        slove(0,n, board,ans);
        return ans;
    }
};