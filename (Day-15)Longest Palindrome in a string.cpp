//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        
        for(int i = 0 ; i < n ; i++){
            
            string curr = "";
            curr +=s[i] ;
            string x =  check_palindrome(i,i+1,"",s,n);
            string y = check_palindrome(i-1,i+1,curr,s,n);
            
            update(x,ans);
            update(y,ans) ;
            
        }
        
        return ans;
    }
    
    void update(string &x, string &ans){
        if(x.size() > ans.size()){
            ans = x ;
        }
    }
    
    string check_palindrome(int first, int second, string mid, string &s, int n){
        string x = "", y = "";

        while(true){
            if(first < 0 or second >= n or s[first] != s[second]) break;
            x += s[first--];
            y += s[second++];
        }

        reverse(x.begin(),x.end());
        
        return (x+mid+y) ;
    }

};
