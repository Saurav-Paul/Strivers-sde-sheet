//https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text2, string text1) {
        int n = text1.size() ;
        int m = text2.size() ;
        
        vector< vector<int> > dp(2,vector<int> (m,0)) ;
        
        int prev = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            int curr = !(prev) ;
            
            for(int j = 0 ; j < m ; j++){
                int x = (text1[i] == text2[j]) ;

                if(j){
                    x = max(x, x + dp[prev][j-1]) ;
                    x = max(x,dp[curr][j-1]) ;

                }
                x = max(x, dp[prev][j]) ;
                dp[curr][j] = x;
            }
            
            prev = curr;
        }
        
        return dp[prev][m-1] ;
    }
};
