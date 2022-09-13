#https://leetcode.com/problems/is-graph-bipartite/
class Solution:

    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n
        
        def bfs(node: int) -> bool:
            queue = []
            queue.append(node)
            
            while queue:
                curr = queue.pop(0)
                curr_color = 0 if color[curr] == -1 else color[curr]
                
                for _node in graph[curr]:
                    if curr_color == color[_node]:
                        return False
                    if color[_node] is not -1:
                        continue
                    color[_node] = 0 if curr_color == 1 else 1
                    queue.append(_node)
            
            return True
        
        for no in range(n):
            if color[no] == -1:
                if not bfs(no):
                    return False
        
        return True
