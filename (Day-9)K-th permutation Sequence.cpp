//https://leetcode.com/problems/permutation-sequence/
class Solution {
public:
    int toInt(char c){
        return int(c-'0') ;
    }
    string getPermutation(int n, int k) {
        string s = "";
        
        for(int i = 1 ; i <= n ; i++){
            s += ( '0' + i ) ;
        }
        
        // we will find next permutation in each time
        while(--k){
            int st = -1, sp = -1;
            for(int i = n - 1 ; i > 0 ; i--){
                if(toInt(s[i]) > toInt(s[i-1])){
                    st = i - 1;
                    break;
                }
            }
            
            for(int j = n -1 ; j > st ; j--){
                if(toInt(s[st]) < toInt(s[j])){
                    sp = j ;
                    break ;
                }
            }
            
            swap(s[st],s[sp]) ;            
            sort(s.begin() + st + 1, s.end()) ;

        }
        
        return s;
    }
};
