//https://leetcode.com/problems/palindrome-partitioning/submissions/
class Solution {
public:
    
    bool isPalindrome(string &s){
        int st = 0, sp = s.size() -1 ;
        while(st <= sp){
            if(s[st] != s[sp]) return false;
            ++st, --sp;
        }
        return true;
    }
    
    void fun(string &s, vector<int> &partition, int index, set<vector<string>> &res){
        if(s.size() == index){
            // check if all partions are palindrome
            vector<string> v;
            
            string temp = "" ;
            
            for(int i = 0 ; i <= s.size() ; i++){
                if(i == s.size() or partition[i] == 1){
                    v.push_back(temp);
                    temp = "" ;
                }
                if(i < s.size())
                    temp += s[i] ; 
            }
            
            res.insert(v) ;
            
            return ;
        }
        string temp = "" ;
        for(int i = 0 ; i <= index ; i++){
            if(partition[i] == 1){
                temp = "" ;
                temp += s[i] ;
            }
            else{
                temp += s[i] ;
            }
        }
        for(int i = index + 1; i <= s.size() ; i++){
            if(isPalindrome(temp)){
                partition[i] = 1;
                fun(s,partition,i,res);
                partition[i] = 0;
            }
            if(i < s.size())
                temp += s[i] ;
        }
    }
    
    vector<vector<string>> partition(string s) {
        set<vector<string>> res;
        vector<int> partition(s.size() + 2, 0) ;
        fun(s,partition,0,res) ;
        vector<vector<string>> ans;
        ans.assign(res.begin(), res.end()) ;
        return ans ;
    }
};
