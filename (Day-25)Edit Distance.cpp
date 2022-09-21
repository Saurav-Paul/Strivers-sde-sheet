//https://leetcode.com/problems/edit-distance/
class Solution {
public:
    vector< vector<int> > dp;
    
    int calc(string &w1, string &w2, int i , int j){
        bool w1_end = (w1.size() == i) ;
        bool w2_end = (w2.size() == j) ;
        
        if(w1_end && w2_end){
            return 0 ;
        }
        
        if(w1_end){
            return w2.size() - j;
        }
        
        if(w2_end){
            return w1.size() - i ;
        }
        
        if(dp[i][j] != -1) return dp[i][j] ;
        
        int ans = INT_MAX;
        // if char is already ok
        if(w1[i] == w2[j]){
            ans = calc(w1,w2,i+1, j+1) ;
        }
        else{
            // inserting
            ans = min(ans, calc(w1,w2,i,j+1) + 1) ;
            
            // deleting
            ans = min(ans, calc(w1,w2,i+1,j) + 1) ;
            
            // replacing
            ans = min(ans, calc(w1,w2,i+1,j+1) +1) ;
        }
        
        return dp[i][j] = ans ;
        
    }
    
    int minDistance(string &word1, string &word2) {
        dp.assign(word1.size(), vector<int> (word2.size(), -1)) ;
        return calc(word1, word2, 0, 0);
    }
};
