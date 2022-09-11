# https://leetcode.com/problems/course-schedule/
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {}
        
        for x in prerequisites:
            f,s = x
            
            # inserting in graph
            if s not in graph:
                graph[s] = []
            
            graph[s].append(f)
            
        visited = set()
        
        dp = {}
        
        def dfs(course: int) -> bool:
            
            if course in visited:
                return False
            
            if course in dp:
                return dp[course]
            
            visited.add(course)
            
            for dependency in graph.get(course, []):
                if not dfs(dependency):
                    return False
                
            visited.remove(course)
            
            dp[course] = True
            
            return dp[course]
        
        
        for course in range(numCourses):
            if not dfs(course):
                return False
        
        return True
