class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:

        n = len(grid)-2
        ans = [[0]*n for _ in range(n)]

        for i,j in product(range(n),range(n)):
            ans[i][j] = max(grid[I][J] for I,J in
                            product(range(i,i+3),range(j,j+3)))

        return  ans
