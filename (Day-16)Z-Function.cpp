//https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int nSize = needle.size() ;
        int hSize = haystack.size() ;
        
        if(hSize < nSize) return - 1;
        
        long long needleHash = getHash(needle, 0, nSize) ;
        long long tempHash = getHash(haystack, 0, nSize) ;
        
        
        if(tempHash ==  needleHash){
            if(isSame(needle, haystack, 0)){
                return 0 ;
            }
        }
        
        for(int i = nSize ; i < hSize; i++){
            tempHash = tempHash - getVal(haystack[i - nSize]) + getVal(haystack[i]) ;
            if(tempHash == needleHash){
                cout << i - nSize + 1 << endl;
                if(isSame(needle,haystack, i - nSize + 1)){
                    return (i - nSize + 1);
                }
            }
        }
        
        
        return - 1;
        
    }
    
    int getVal(char c){
        // get individual character hashVal
        int prime = 101 ;
        return (prime * c);
    }
    
    long long getHash(string &needle, int st, int n){
        // function for getting the Hash value
        long long hash = 0 ;
        for(int i = st ; i < st + n ; i++){
            hash += getVal(needle[i]) ;
        }
        return hash ;
    }
    
    bool isSame(string &needle, string &haystack, int st){
        // function for checking if strings are same
        for(int i = 0 ; i < needle.size() ; i++){
            if(needle[i] != haystack[i+st]) return false;
        }
        return true ;
    }
};
