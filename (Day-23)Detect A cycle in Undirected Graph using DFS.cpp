//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    vector<vector<int>> graph ;
    vector<bool> visited;
    
    map<int, bool> rem ;
    
    bool traverse(int pos){
        if(visited[pos]) return false;
        
        if(rem.find(pos) != rem.end()) return rem[pos] ;
        
        visited[pos] = true ;
        
        for(auto x : graph[pos]){
            bool ok = traverse(x) ;
            if(!ok) return false;
        }
        
        visited[pos] = false;
        
        return rem[pos]=true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int limit = 2001;
        visited.assign(limit, false) ;
        graph = vector < vector<int> > (limit, vector<int> ()) ;
        
        for(auto x : prerequisites){
            int f=x[0], s=x[1] ;
            
            graph[s].push_back(f) ;
        }
        
        for(int i = 0 ; i < limit ; i++){
            if(visited[i] == false && graph[i].size() > 0){
                bool ok = traverse(i) ;
                if(!ok) return false;
            }
        }
        
        return true;
    }
};
