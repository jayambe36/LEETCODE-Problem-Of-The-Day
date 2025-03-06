class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        bag = set()
        duplicate = -1
        n = len(grid)
        
        for i in range(n):
            for j in range(n):
                now = grid[i][j]
                if now in bag:
                    duplicate = now
                bag.add(now)
                
        for i in range(1, n*n+1):
            if i not in bag:
                return [duplicate, i]
            
        raise ValueError("Error")