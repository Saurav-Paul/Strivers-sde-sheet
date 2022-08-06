//https://leetcode.com/problems/combination-sum-ii/submissions/
class Solution {
public:
    void combination_sum(vector<int> &candidates,int index, int sum, int target, vector<int> v, set<vector<int>> &_set){
        if(sum == target){
            _set.insert(v) ;
            return ;
        }
        if(sum > target) return ;
        
        for(int i = index ; i < candidates.size() ; i++){
            v.push_back(candidates[i]) ;
            if(i == index or (candidates[i] != candidates[i-1])){
                combination_sum(candidates, i+1, sum + candidates[i], target, v, _set);
            }
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()) ;
        set<vector<int>>_set;
        vector<int> v;
        vector< vector<int> > res;
        combination_sum(candidates,0,0,target,v,_set) ;
        res.assign(_set.begin(),_set.end());
        return res;
    }
};
