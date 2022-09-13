# https://leetcode.com/problems/is-graph-bipartite/
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n
        
        def dfs(node: int , prev_color : int) -> bool:
            if color[node] is prev_color:
                return False
            if color[node] is not -1:
                return True
            
            curr_color = 0 if prev_color is 1 else 1
            color[node] = curr_color
            
            for _node in graph[node]:
                if not dfs(_node, curr_color):
                    return False
            
            return True
        
        for no in range(n):
            if color[no] == -1:
                if not dfs(no,0):
                    return False
                
        
        return True
