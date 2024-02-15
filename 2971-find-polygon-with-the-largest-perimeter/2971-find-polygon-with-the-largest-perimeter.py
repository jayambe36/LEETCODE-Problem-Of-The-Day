class Solution:
    def largestPerimeter(self, nums):
        nums.sort()
        total_sum = 0
        ans = -1
        
        for num in nums:
            if num < total_sum:
                ans = num + total_sum
            total_sum += num
        
        return ans
