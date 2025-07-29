class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        for i in range(n):
            x = nums[i]
            res[i] = 1
            j = i - 1
            while j >= 0 and (nums[j] | x) != nums[j]:
                res[j] = i - j + 1
                nums[j] |= x
                j -= 1
        return res
