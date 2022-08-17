//https://leetcode.com/problems/valid-parentheses/
class Solution {
    
    string starting = "({[";
    string ending = ")}]" ; 
    
    bool start_item(char c){
        for(auto x : starting){
            if(c == x) return true;
        }
        return false;
    }
    
    char get_expected_bracket(char c){
        for(int i = 0 ; i < ending.size() ; i++){
            if(ending[i] == c){
                return starting[i] ;
            }
        }
        
        // not getting the correct input
        assert(false) ;
    }
    
    char getTop(stack<char> &stk){
        if(stk.size() == 0) return ' ';
        return stk.top();
    }
    
    public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(auto c : s){
            if(start_item(c)){
                stk.push(c) ;
            }
            else{
                if(stk.size() == 0) return false;
                char expected_bracket = get_expected_bracket(c) ;
                if(getTop(stk) == expected_bracket){
                    stk.pop() ;
                }
                else return false;
            }
        }
        
        return (stk.size() == 0);
    }
};
