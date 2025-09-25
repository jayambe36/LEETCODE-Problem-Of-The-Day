class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        for row in range(n - 1, 0, -1):
            for col in range(len(triangle[row]) - 1):
                triangle[row - 1][col] = triangle[row - 1][col] + min(triangle[row][col], triangle[row][col + 1])
        return triangle[0][0]