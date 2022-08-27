//https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1" ;
        }
        
        string s = countAndSay(n - 1) ;
        string res = "" ;
        
        int cnt = 0;
        char c;

        for(int i = 0 ; i < s.size() ; i++){
            if(i == 0){
                c = s[i] ;
                ++ cnt ;
            }
            else{
                if(c == s[i]){
                    ++ cnt ;
                }
                else{
                    res += getVal(cnt, c) ;
                    cnt = 1;
                    c = s[i] ;
                }
            }
        }
        
        if(cnt > 0){
            res += getVal(cnt,c) ;
        }
        
        return res ;
    }
    
    string getVal(int cnt, char c){
        
        string x = "";
        while(cnt > 0){
            int digit = cnt % 10;
            cnt /= 10 ;
            x += char('0' + digit) ;
        }
        reverse(x.begin(),x.end()) ;
        x += c;

        return x ;
    }
};
