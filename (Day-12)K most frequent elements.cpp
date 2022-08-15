//https://leetcode.com/problems/top-k-frequent-elements/submissions/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp ;
        for(auto x : nums){
            mp[x] ++;
        }
        
        auto compare = [](pair<int,int> a, pair<int,int> b)
            {
                return a.second < b.second;
            };
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , decltype(compare)> pq(compare);
        
        
        for(auto x : mp){
            pq.push(x) ;
        }
        
        vector<int> ans ;
        
        while(k--){
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(p.first) ;
        }
        
        return ans;
        
    }
};
