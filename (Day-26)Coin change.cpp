//https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int inf = 1e9 + 90 ;
        vector<int> dp(amount + 1, inf) ;
        dp[0] = 0 ;
        for(auto coin: coins){
            for(int i = coin ; i <= amount ; i ++){
                dp[i] = min(dp[i],dp[i-coin] + 1);
            }
        }
        if(dp[amount] == inf) dp[amount] = - 1;
        return dp[amount];
    }
};
