// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row_zero(n), col_zero(m);
        
        for(int i = 0 ; i < n ;i ++){
            for(int j= 0 ; j < m ; j++){
               if(matrix[i][j] == 0){
                   col_zero[j] = true;
                   row_zero[i] = true;
               } 
            }   
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(row_zero[i] || col_zero[j]){
                   matrix[i][j] = 0;
                }
            }
        }
    }
};
