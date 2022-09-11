//Detect A cycle in Undirected Graph using BFS
class Solution {
public:    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector< vector<int> > graph(numCourses, vector<int> ()) ;
        int counter = 0 ;
        vector<int> inorder(numCourses) ;
        
        for(auto x : prerequisites){
            int f = x[0], s = x[1] ;
            graph[s].emplace_back(f) ;
            inorder[f] ++;
        }
        
        queue<int> q;
        
        for(int i = 0 ; i < numCourses; i++){
            if(inorder[i] == 0)
                q.push(i) ;
        }
        
        while(!q.empty()){
            counter ++ ;
            int top = q.front();
            q.pop();
            
            for(auto x : graph[top]){
                --inorder[x];
                if(inorder[x] == 0)
                    q.push(x) ;
            }
        }
        
        return (counter == numCourses);
    }
};
