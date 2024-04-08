class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.atlantic = []
        self.pacific = []
        self.ans = []

    def pacificAtlantic(self, mat):
        if not mat:
            return self.ans
        self.m = len(mat)
        self.n = len(mat[0])
        self.atlantic = [[False] * self.n for _ in range(self.m)]
        self.pacific = [[False] * self.n for _ in range(self.m)]

        for i in range(self.m):
            self.dfs(mat, self.pacific, i, 0)
            self.dfs(mat, self.atlantic, i, self.n - 1)

        for i in range(self.n):
            self.dfs(mat, self.pacific, 0, i)
            self.dfs(mat, self.atlantic, self.m - 1, i)

        return self.ans

    def dfs(self, mat, visited, i, j):
        if visited[i][j]:
            return
        visited[i][j] = True

        if self.atlantic[i][j] and self.pacific[i][j]:
            self.ans.append([i, j])

        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dx, dy in directions:
            x, y = i + dx, j + dy
            if 0 <= x < self.m and 0 <= y < self.n and mat[x][y] >= mat[i][j]:
                self.dfs(mat, visited, x, y)


# Example usage:
# sol = Solution()
# matrix = [
#     [1, 2, 2, 3, 5],
#     [3, 2, 3, 4, 4],
#     [2, 4, 5, 3, 1],
#     [6, 7, 1, 4, 5],
#     [5, 1, 1, 2, 4]
# ]
# print(sol.pacificAtlantic(matrix))
