//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        int i = 0 ;
        while(true){
            bool isOk = true ;
            bool shes = false ;
            bool first = true;
            char c = '-';
            
            for(auto s : strs){
                if(s.size() == i){
                    shes = true ;
                    isOk = false;
                    break ;
                }
                if(first){
                    first = false ;
                    c = s[i];
                }
                else if(c != s[i]){
                    isOk = false;
                    break ;
                }
            }
            
            if(isOk) ans += c;
            else break ;
            ++ i ;
        }
        
        return ans ;
    }
};
