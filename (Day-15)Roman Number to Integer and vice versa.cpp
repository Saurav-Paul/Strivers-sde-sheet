//https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        
        map<char,int> mp;
        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int cnt = 0 ;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(i == 0) cnt += mp[s[i]] ;
            else{
                int last = mp[s[i-1]] ;
                int curr = mp[s[i]] ;
                
                if(curr <= last){
                    cnt += curr;
                }
                else{
                    cnt -= (2 * last) ;
                    cnt += curr;
                }
            }
        }
        
        return cnt ;
    }
};
