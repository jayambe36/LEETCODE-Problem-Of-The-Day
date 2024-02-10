class Solution:
    def countSubstrings(self, s: str) -> int:
        return sum((q:=s[i:j+1])==q[::-1] for i in range(len(s)) for j in range(i,len(s)))
