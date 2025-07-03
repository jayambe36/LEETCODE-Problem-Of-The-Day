class Solution:
    def kthCharacter(self, k: int) -> str:
        s = "a"
        while len(s) < k:
            next_part = ''.join(chr(((ord(c) - ord('a') + 1) % 26) + ord('a')) for c in s)
            s += next_part
        return s[k - 1]