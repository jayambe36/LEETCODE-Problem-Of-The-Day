from collections import deque

class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.ans = []
        self.atlantic = []
        self.pacific = []
        self.q = deque()

    def pacificAtlantic(self, mat):
        if not mat:
            return self.ans
        self.m = len(mat)
        self.n = len(mat[0])
        self.atlantic = [[False] * self.n for _ in range(self.m)]
        self.pacific = [[False] * self.n for _ in range(self.m)]

        for i in range(self.m):
            self.bfs(mat, self.pacific, i, 0)
            self.bfs(mat, self.atlantic, i, self.n - 1)

        for i in range(self.n):
            self.bfs(mat, self.pacific, 0, i)
            self.bfs(mat, self.atlantic, self.m - 1, i)

        return self.ans

    def bfs(self, mat, visited, i, j):
        self.q.append((i, j))
        while self.q:
            i, j = self.q.popleft()
            if visited[i][j]:
                continue
            visited[i][j] = True
            if self.atlantic[i][j] and self.pacific[i][j]:
                self.ans.append([i, j])
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dx, dy in directions:
                x, y = i + dx, j + dy
                if 0 <= x < self.m and 0 <= y < self.n and mat[x][y] >= mat[i][j]:
                    self.q.append((x, y))

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
