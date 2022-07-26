//https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    
    bool compareFn (vector<int> a, vector<int> b){
           return a[0] < b[0] ; 
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
           return a[0] < b[0] ; 
        });
        
        vector<vector<int>> ans ;
        int n = intervals.size();
        int st = intervals[0][0] ;
        int sp = intervals[0][1] ;
        
        for(int i = 1 ; i < n ; i++){
            int x = intervals[i][0] ;
            int y = intervals[i][1] ;
            
            if(sp >= x){
                if(st <= y){
                    sp = max(sp, y) ;
                    st = min(st, x) ;
                }
                else{
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y) ;
                    ans.push_back(temp) ;
                }
            }else{
                vector<int> temp;
                temp.push_back(st);
                temp.push_back(sp) ;
                ans.push_back(temp) ;
                
                st = x;
                sp = y;
            }
        }

        vector<int> temp;
        temp.push_back(st);
        temp.push_back(sp) ;
        ans.push_back(temp) ;
        
        return ans;
    }
};
