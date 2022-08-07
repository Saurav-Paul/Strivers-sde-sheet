//https://leetcode.com/problems/n-queens/
class Solution {
public:
    
    bool isItPossible(int x, int y , vector<pair<int,int>> &queens){
        
        for(auto q : queens){
            int xx = q.first , yy = q.second ;
            if(x == xx or y == yy) return false;
            if(abs(x-xx) == abs(y-yy)) return false;
        }
        
        return true;
    }
    
    void n_queens(int index, vector<pair<int,int>> &queens, int n, vector<vector<pair<int,int>>> &res){
        if(index > n - 1){
            res.push_back(queens) ;
            return ;
        }
        for(int i = 0 ; i < n ; i++){
            int x = index, y = i ;
            
            if(isItPossible(x,y,queens)){
                pair<int,int> p = {x,y} ;
                queens.push_back(p);
                n_queens(index + 1, queens, n , res) ;
                queens.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string temp = "" ;
        for(int i = 0 ; i < n; i++) temp += '.' ;
        vector<string> v(n,temp) ;
        vector<vector<pair<int,int>>> res;
        vector<pair<int,int>> queens ;
        
        n_queens(0,queens,n,res) ;
        
        cout << res.size() << endl;
        
        vector<vector<string>> ansList ;
        
        for(int i = 0 ; i < res.size() ; i++){
            auto queens_pos = res[i] ;
            vector<string> ans = v;
            
            for(auto p: queens_pos){
                ans[p.first][p.second] = 'Q' ;
            }
            
            ansList.push_back(ans) ;
        }
        

        
        return ansList;
    }
};
