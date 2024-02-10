#Time complexity: $$O(n^2)$$. Space complexity: $$O(n)$$.

class Solution:
    def countSubstrings(self, s: str) -> int:
        return (f:=lambda l,r:0<=l<=r<len(s) and s[l]==s[r] and 1+f(l-1,r+1)) and \
            sum(f(i,i)+f(i-1,i) for i in range(len(s)))
