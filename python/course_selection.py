"""
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi 
first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. 
So it is impossible.
"""
def dfs_cycle_detection(node, visited, recstack, adj, n):
  visited[node] = 1 
  recstack[node] = 1 
  
  for i in range(n):
    if adj[node][i]:
      if not visited[i] and dfs_cycle_detection(i, visited, recstack, adj, n):
        return True
      elif(recstack[i]):
        return True
        
  recstack[node] = 0
  return False

def topological_sort(adj, n):
  visited = [0] * n;
  recstack = [0] * n;
  
  for i in range(n):
    if dfs_cycle_detection(i, visited, recstack, adj, n):
      return False
      
  return True

def course_schedule_possible(numCourses, prerequisites):
  adj = [[0] * numCourses for _ in range(numCourses)]
  for prerequisite in prerequisites:
    adj[prerequisite[0]][prerequisite[1]] = 1;
    
  if topological_sort(adj, numCourses):
    return True
  else :
    return False
  
"""
numCourses = 2;
prerequisites = [[1, 0]]

course_schedule_possible(numCourses, prerequisites)
"""

def run_tests():
    test_cases = [
        # Test Case 1: No prerequisites, multiple courses
        (5, [], True),
        
        # Test Case 2: Single course, no prerequisites
        (1, [], True),
        
        # Test Case 3: Two courses with valid prerequisite
        (2, [[1, 0]], True),
        
        # Test Case 4: Two courses with circular dependency
        (2, [[1, 0], [0, 1]], False),
        
        # Test Case 5: Multiple courses, no cycles
        (4, [[1, 0], [2, 1], [3, 2]], True),
        
        # Test Case 6: Multiple courses, cycle exists
        (4, [[1, 0], [2, 1], [3, 2], [0, 3]], False),
        
        # Test Case 7: Disconnected graph
        (5, [[1, 0], [3, 2]], True),
        
        # Test Case 8: Large input with no dependencies
        (1000, [], True),
        
        # Test Case 9: Large input with a cycle
        (500, [[i, i + 1] for i in range(499)] + [[499, 0]], False),
        
        # Test Case 10: Courses with multiple dependencies
        (6, [[1, 0], [2, 1], [3, 1], [4, 2], [5, 4]], True),
        
        # Test Case 11: Reverse order of dependencies
        (3, [[0, 1], [1, 2]], True),
        
        # Test Case 12: Self-dependency on a single course
        (1, [[0, 0]], False),
        
        # Test Case 13: Multiple independent cycles
        (6, [[1, 0], [0, 1], [3, 2], [2, 3]], False),
    ]
    
    for idx, (numCourses, prerequisites, expected) in enumerate(test_cases):
        result = course_schedule_possible(numCourses, prerequisites)
        assert result == expected, f"Test case {idx + 1} failed: Expected {expected}, got {result}"
        print(f"Test case {idx + 1} passed.")

run_tests()
