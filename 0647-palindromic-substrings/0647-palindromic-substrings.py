#Time complexity: $$O(n^2)$$. Space complexity: $$O(1)$$.

class Solution:
    def countSubstrings(self, s: str) -> int:
        return (f:=lambda l,r:sum(takewhile(int,(s[l-i]==s[r+i] for i in range(min(l+1,len(s)-r)))))) and \
            sum(f(i,i)+f(i-1,i) for i in range(1,len(s)))+1
