//https://leetcode.com/problems/sudoku-solver/
class Solution {   
public:
    
    int n = 9 ;
    
    void findFreq(vector<vector<char>> &board, int x, int y, map<char,int> &rem){
        for(int i = 0 ; i < n ; i++){
            if(board[i][y] != '.'){
                rem[board[i][y]] ++ ;
            }
            
            if(board[x][i] != '.'){
                rem[board[x][i]] ++ ;
            }
        }
    }
    
    bool isValid(vector<vector<char>> &board, int x, int y,char num){
        for(int i = 0 ; i < n ; i++){
            if(board[i][y] == num or board[x][i] == num){
                return false ;
            }
            if (board[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == num)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board){
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){

                if(board[i][j] == '.'){
                    for(int k = 1 ; k <= n ; k++){
                        char c = k + '0' ;
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            bool ok =solve(board);
                            if(ok) return true ;
                            board[i][j] = '.' ;
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board) ;
    }
};
