//https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s) {
        string num = "";
        bool first = false;
        char sign = ' ' ;
        
        for(auto x : s){
            if(first == false && x == ' ') continue ;

            if((x == '-' or x == '+') and first == false){
                if(sign == ' '){
                    sign = x ;
                }
                else{
                    break ;
                }
            }
            else{
            
                int curr = int(x - '0');

                if(curr < 0 or curr > 9) break ;

                num += x ;
            }
            
            first = true ;
            
        }
        
        long long n = 0 , mx = INT_MAX ;
        
        for(int i = 0 ; i < num.size() ; i++){
            n *= 10 ;
            n += int(num[i] - '0') ;
            
            if(sign == '-'){
                if(n >= mx + 1){
                    n = mx + 1;
                    break ;
                }
            }
            else{
                if(n >= mx){
                    n = mx ;
                    break ;
                }
            }
        }
        
        if(sign == '-') n *= -1 ;
        
        return n ;
    }
};
