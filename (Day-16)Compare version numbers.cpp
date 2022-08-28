//https://leetcode.com/problems/compare-version-numbers/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        return getAnswer(version1, version2);
    }
    
    int toInt(string &a){
        int prev = 0 ;
        for(int i = 0 ; i < a.size() ; i++){
            int digit = (a[i] - '0') ;
            prev *= 10 ;
            prev += digit ;
        }
        return prev ;
    }
    
    vector<int> getInNumber(string &a){
        vector<int> va ;
        string s = "" ;
        for(auto x : a){
            if(x == '.'){
                va.push_back(toInt(s)) ;
                s = "";
            }
            else s += x ;
        }
        va.push_back(toInt(s)) ;
        while(va.size() > 0 && va.back() == 0) va.pop_back() ;
        return va;
    }
    
    int getAnswer(string &a, string &b){
        vector<int> va = getInNumber(a), vb = getInNumber(b);
        
        int na = va.size() , nb = vb.size() ;
        
        for(int i = 0 ; i < min(na,nb) ; i++){
            if(va[i] > vb[i])
                return 1;
            
            if(va[i] < vb[i])
                return -1;
        }
        
        if(na > nb) return 1;
        else if(na < nb) return -1;
        else{
            return 0 ;
        }
        
        return 0 ;
    }

};
