//https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN ;
        for(auto x : nums) mx = max(mx, x) ;
        
        int prod = 0, lastMinus = 1;
        
        for(auto x : nums){
            if(x == 0){
                prod = 0;
                lastMinus = 1;
            }
            
            if(prod == 0) prod = x;
            else {
                prod *= x;
                int temp = max(prod, prod/lastMinus) ;
                mx = max(mx, temp) ;    
            }
            
            if(x < 0 && lastMinus == 1){
                lastMinus = prod ;
                mx = max(mx, prod) ;
            }

            

        }
        
        return mx ;
    }
};
