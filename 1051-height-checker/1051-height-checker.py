class Solution:
       def heightChecker(self, heights: List[int]) -> int:
        cnt = collections.Counter(heights)
        i, ans = 1, 0
        for h in heights:
            while cnt[i] == 0: # non-exist height.
                i += 1         # skip it.
            if i != h:         # mismatch found.
                ans += 1       # increase by 1.
            cnt[i] -= 1        # remove the one that has been used.
        return ans