//https://leetcode.com/problems/ones-and-zeroes/
class Solution {
public:
    
    pair<int,int> get_count(string &s){
        int zero = 0, one = 0 ;
        
        for(auto c : s){
            if(c == '0') zero ++;
            else if(c == '1') one ++;
            else assert(false) ;
        }
        
        return make_pair(zero, one) ;
    }
    

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size() ;
        
        vector< vector<int> > dp(m + 1, vector<int> (n+1, 0)) ;
        int ans = 0 ;
        
        for(int i = 0 ; i < sz ; i++){
            pair<int,int> p = get_count(strs[i]) ;
            int _m = p.first , _n = p.second ;
            
            for(int j = m ; j - _m >= 0 ; j--){
                for(int k = n ; k - _n >= 0 ; k--){
                    if(dp[j-_m][k-_n] > 0 or (j-_m == 0 and k-_n ==0)){
                        dp[j][k] = max(dp[j][k], 1 + dp[j-_m][k-_n]);
                        ans = max(ans, dp[j][k]) ;
                    }
                }
            }
        }
        
        return ans;
        
    }
};
