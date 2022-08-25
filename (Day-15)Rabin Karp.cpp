//https://leetcode.com/problems/repeated-string-match/
class Solution {
    int prime = 11;
public:
    int repeatedStringMatch(string a, string b) {
        int na = a.size() ;
        int nb = b.size() ;
        
        int temp = nb + (na-1) ;
        temp /= na ;
        
        long long hash = getHashValue(b) ;
        
        string tempS = "" ;
        
        for(int i = 0 ; i < temp ; i++){
            tempS += a ;
        }

        bool ok = checkIfMatched(tempS,b ,hash) ;
        
        if(ok) return temp ;
        tempS += a ;
        ok = checkIfMatched(tempS, b, hash);
        if(ok) return temp + 1;
        
        return -1 ;
    }
    
    bool checkIfMatched(string &a, string &b, long long hash){
        int na = a.size();
        int nb = b.size();
        
        long long initialHash = 0 ;
        for(int i = 0 ; i < nb ; i++){
            initialHash = (initialHash + a[i] * prime)  ;
        }
        
        
        if(hash == initialHash){
            bool check = isSame(b,a, 0) ;
            if(check) return true ;
        }
        
        for(int i = nb ; i < na ; i++){
            initialHash = (initialHash - a[i-nb] * prime + a[i] * prime ) ;
            if(hash == initialHash){
                bool check = isSame(b,a, i - nb + 1) ;
                if(check) return true ;
            }
        }
        
        
        return false ;
    }
    
    bool isSame(string &a, string &b, int st){
        for(int i = 0 ; i < a.size() ; i ++){
            if(a[i] != b[i+st]) return false;
        }
        return true ;
    }
    
    long long getHashValue(string &s){
        int n = 0 ;
        for(auto x : s){
            n = (n + x * prime) ;
        }
        return n ;
    }
};
