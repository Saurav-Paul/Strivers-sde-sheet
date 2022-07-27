// https://leetcode.com/problems/search-a-2d-matrix/submissions/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size() ;
        
        for(int i = 0 ; i < n ; i++){
            if(matrix[i][m-1]  >= target){
                for(int j = m - 1 ; j >= 0 ; j--){
                    if(matrix[i][j] == target) return true;
                }
                return false;
            }
        }
        return false;
    }
};
