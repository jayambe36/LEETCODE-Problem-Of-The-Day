class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7
        power = 1
        while power <= n:
            power <<= 1
        power >>= 1
        parts = []
        m = n
        while m > 0:
            if power <= m:
                parts.append(power)
                m -= power
            power >>= 1
        k = len(parts)
        prefix = [[0] * k for _ in range(k)]
        for i in range(k):
            prefix[i][i] = parts[k - 1 - i]
            for j in range(i + 1, k):
                prefix[i][j] = (prefix[i][j - 1] * parts[k - 1 - j]) % mod
        res = []
        for l, r in queries:
            res.append(prefix[l][r])
        return res