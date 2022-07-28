//https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int> > v(m, vector<int>(n,0)) ;
        
        v[0][0] = 1;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(j - 1 >= 0){
                    v[i][j] += v[i][j-1] ;
                }
                if(i - 1 >= 0){
                    v[i][j] += v[i-1][j] ;
                }
            }
        }
        
        return v[m-1][n-1] ;
    }
};
