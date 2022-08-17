//https://leetcode.com/problems/next-greater-element-i/submissions/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int n = nums2.size() ;

        unordered_map<int,int> mp ;
        
        for(int i = n - 1; i >= 0; i--){
            int num = nums2[i] ;

            while(stk.size()){
                if(stk.top() < num) stk.pop();
                else{
                    mp[num] = stk.top();
                    break;
                }
            }

            stk.push(num) ;
        }
        
        vector<int> res ;
        for(auto x : nums1){
            int temp = mp[x] ;
            res.push_back(temp == 0 ? -1 : temp) ;
        }
        
        return res ;
    }
};
