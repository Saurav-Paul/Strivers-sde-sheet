//https://leetcode.com/problems/rotting-oranges/
class Solution {
    
    vector<vector<int> > ttr, isVisited;
    
    bool isOk(vector< vector<int> > &grid, int x, int y, int cnt){
        int n = ttr.size();
        int m = ttr[0].size();
        if(x < 0 || y < 0) return false;
        if(x == n || y == m) return false;
        
        if(ttr[x][y] <= cnt) return false;
        if(grid[x][y] != 1) return false;
        
        return true;
    }
    
    void bfs(vector<vector<int>> &grid, int x, int y,int cnt){
        if(cnt  and !isOk(grid,x,y,cnt)){
            return ;
        }

        ttr[x][y] = cnt ;
        
        bfs(grid,x+1,y, cnt+1) ;
        bfs(grid,x-1,y, cnt+1) ;
        bfs(grid,x,y+1, cnt+1) ;
        bfs(grid,x,y-1, cnt+1) ;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int inf = 1e9 + 9 ;
        
        ttr = vector< vector<int> > (n, vector<int> (m,inf));
        isVisited = vector< vector<int> > (n, vector<int> (m,0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2)
                    ttr[i][j] = 0 ;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    bfs(grid,i,j,0);
                }
            }
        }
        
        int ans =  0 ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1)
                    ans = max(ans,ttr[i][j]) ;
            }
        }
        
        return (ans == inf ? -1 : ans) ;
    }
};
