//https://leetcode.com/problems/sliding-window-maximum/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res ;
        queue<int> q ;
        multiset<int> st ;
        
        for(int i = 0 ; i < k ; i++){
            q.push(nums[i]) ;
            st.insert(nums[i]) ;
        }
        
        res.push_back(getMax(st)) ;
        
        for(int i = k ; i < nums.size() ; i++){
            
            // extracting last number
            int ex = q.front();
            q.pop();
            st.erase(st.lower_bound(ex));
            
            //inserting new number
            int num = nums[i] ;
            q.push(num) ;
            st.insert(num) ;
            
            res.push_back(getMax(st)) ;
            
        }
        
        return res ;
    }
    
    int getMax(multiset<int> &st){
        return *(st.rbegin()) ;
    }
    
};
