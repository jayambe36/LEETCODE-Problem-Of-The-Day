class Solution:
    def rev(self, n):
        re = 0
        while n > 0:
            re = re * 10 + n % 10
            n //= 10
        return re

    def fact(self, n):
        if n == 1:
            return 1
        return n + self.fact(n - 1)

    def countNicePairs(self, nums):
        count = 0
        mod = 1000000007

        for i in range(len(nums)):
            nums[i] = nums[i] - self.rev(nums[i])

        mp = Counter(nums)

        for key, value in mp.items():
            if value > 1:
                count = (count % mod + self.fact(value - 1)) % mod

        return int(count)
