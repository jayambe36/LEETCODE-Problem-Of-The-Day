from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        end = 0
        start = 0

        max_len = 0
        max_count_in_window = 0  # the name is misleading, it is actually the max number of times a character appears in s[0..end]

        count = defaultdict(int)

        for end in range(len(s)):
            count[s[end]] += 1
            max_count_in_window = max(count[s[end]], max_count_in_window)
            if end - start + 1 - max_count_in_window > k:
                count[s[start]] -= 1
                start += 1
            max_len = max(max_len, end - start + 1)

        return max_len
