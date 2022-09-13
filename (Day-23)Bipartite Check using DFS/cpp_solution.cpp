//https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    const int n = 101;
    
    vector<int> color ;
    
    bool traverse(vector<vector<int>>& graph, int node, int prevCol){

        if(color[node] == prevCol) return false;
        if(color[node] != -1) return true;
        
        int currCol = !prevCol ;
        color[node] = currCol ;
        
        for(auto nd : graph[node]){
            if(traverse(graph, nd, currCol) == false)
                return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        color.assign(n+1, -1) ;
        
        for(int i = 0 ; i < graph.size() ; i++){
            if(color[i] == -1){
                if( traverse(graph, i, 0) == false)
                    return false;
            }
        }
        
        return true;
    }
};
