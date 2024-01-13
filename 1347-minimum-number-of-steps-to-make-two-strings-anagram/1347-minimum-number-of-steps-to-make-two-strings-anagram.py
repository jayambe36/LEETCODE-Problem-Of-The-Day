class Solution:
    def minSteps(self, s: str, t: str) -> int:
        T = Counter(t)
        S = Counter(s)
        return sum((S-T).values())
