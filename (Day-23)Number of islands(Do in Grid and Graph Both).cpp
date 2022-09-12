//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    
    void traverse(vector<vector<char>>& grid, vector<vector<int>> &visited, int i , int j){

        
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        if(i < 0 || i == n) return ;
        if(j < 0 || j == m) return ;
        
        if(visited[i][j] == 1 or grid[i][j] == '0') return ;
        
        visited[i][j] = 1 ;
        
        traverse(grid,visited, i-1,j);
        traverse(grid,visited, i+1,j);
        traverse(grid,visited, i,j-1);
        traverse(grid,visited, i,j+1);

    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> visited(n, vector<int> (m,0)) ;
        
        int _count = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    ++ _count ;
                    traverse(grid, visited, i, j) ;
                }
            }
        }
        
        return _count ;
    }
};
