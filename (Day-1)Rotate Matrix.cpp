//https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        cout << n << " " << m << endl;
        vector<vector<int>> new_matrix = matrix ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                new_matrix[j][n-i -1] = matrix[i][j] ;
            }
        }
        matrix = new_matrix;
    }
};
