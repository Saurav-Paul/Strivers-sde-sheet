//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0, temp = 0, last_index = -1;
        
        unordered_map<char, int> mp;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(mp.find(s[i]) != mp.end()){
                
                int temp_index = mp[s[i]] ;
                
                if(temp_index > last_index){
                    temp = i - mp[s[i]] - 1;
                    last_index = temp_index ;
                }

            }
            
            temp ++ ;
            mx = max(temp,mx) ;
            mp[s[i]] = i ;
            
        }
        
        return mx;
    }
};
