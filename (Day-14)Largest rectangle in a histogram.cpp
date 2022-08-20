//https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size(), mx = 0;
        vector<int> nextSmallerElement(n,n), prevSmallerElement(n,-1) ;
        stack< pair<int,int> > stk;
        
        for(int i = 0 ; i < n; i++){
            int val = -1 ;
            int num = heights[i] ;
            
            while(stk.size()){
                pair<int,int> top = stk.top();
                if(top.first < num){
                    val = top.second;
                    break;
                }
                stk.pop();
            }

            stk.push({num, i}) ;
            prevSmallerElement[i] = val;
        }
        
        stk = stack<pair<int,int>> () ;
        
        for(int i = n - 1  ; i >= 0 ; i--){
            int val = n ;
            int num = heights[i] ;
            
            while(stk.size()){
                pair<int,int> top = stk.top();
                if(top.first < num){
                    val = top.second ;
                    break ;
                }
                stk.pop();
            }

            stk.push({num, i}) ;
            nextSmallerElement[i] = val;
        }
        
        
        for(int i = 0 ; i < n ; i++){
            int num = heights[i] ;
            mx = max(mx, (nextSmallerElement[i] - prevSmallerElement[i] - 1) * num) ;
        }
        
        return mx;

    }
};
