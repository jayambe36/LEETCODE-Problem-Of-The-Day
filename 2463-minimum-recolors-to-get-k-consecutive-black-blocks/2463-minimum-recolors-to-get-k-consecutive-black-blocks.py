class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n, mi = len(blocks), inf
        for i in range(n - k + 1):
            white = blocks.count('W', i, i + k)
            mi = min(white, mi)
        return mi