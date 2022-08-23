//https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string temp = "" ;
        
        for(auto x : s){
            if(x == ' '){
                if(temp != "") v.push_back(temp) ;
                temp = "";
            }
            
            if(x != ' ')
            temp += x ;
        }
        
        if(temp != "") v.push_back(temp) ;
        
        temp = "";
        for(int i = v.size() - 1; i >= 0 ; i--){
            temp += v[i] ;
            if(i) temp += " ";
        }
        
        return temp ;
    }
};
