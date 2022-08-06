//https://leetcode.com/problems/combination-sum/submissions/
class Solution {
public:
    
    void combination_sum(vector<int> &candidates,int index, vector<int> v, int sum,int target , vector<vector<int>> &res){
        if(sum == target){
            res.push_back(v) ;
            return ;
        }
        if(sum > target) return ;
        
        for(int i = index ; i < candidates.size() ; i ++){
            
            
            int lft = target - sum ;
            
            int times = lft/candidates[i] ;
            for(int t = 1 ; t <= times ; t++){
                v.push_back(candidates[i]) ;
                combination_sum(candidates,i+1, v, sum + t * candidates[i] , target, res);
            }
            for(int t = 1 ; t <= times ; t++)
                v.pop_back() ;
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector< vector<int> > res ;
        combination_sum(candidates,0, v, 0 , target, res) ;
        return res;
    }
};
