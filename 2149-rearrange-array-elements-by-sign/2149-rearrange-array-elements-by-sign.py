class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pi = 0
        ni = 1
        res = [0] * len(nums)
        
        for n in nums:
            if n > 0:
                res[pi] = n
                pi += 2
            else:
                res[ni] = n
                ni += 2
        
        return res
