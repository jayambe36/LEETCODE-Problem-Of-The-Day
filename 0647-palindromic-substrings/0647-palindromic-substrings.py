#Time complexity: $$O(n^3)$$. Space complexity: $$O(1)$$.

class Solution:
    def countSubstrings(self, s: str) -> int:
        return sum((q:=s[i:j+1])==q[::-1] for i,j in combinations(range(len(s)),2))+len(s)
