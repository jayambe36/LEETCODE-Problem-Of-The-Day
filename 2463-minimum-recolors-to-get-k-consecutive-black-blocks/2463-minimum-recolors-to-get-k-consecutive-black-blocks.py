class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        lo, white, mi = -1, 0, inf
        for hi, c in enumerate(blocks):
            if c == 'W':
                white += 1
            if hi - lo >= k:
                mi = min(white, mi)
                lo += 1
                white -= blocks[lo] == 'W' 
        return mi