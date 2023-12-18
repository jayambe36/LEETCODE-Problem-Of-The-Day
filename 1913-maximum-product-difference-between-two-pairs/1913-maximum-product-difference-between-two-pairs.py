class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        smallest1, smallest2 = float('inf'), float('inf')
        largest1, largest2 = float('-inf'), float('-inf')

        for num in nums:
            if num <= smallest1:
                smallest2, smallest1 = smallest1, num
            elif num <= smallest2:
                smallest2 = num

            if num >= largest1:
                largest2, largest1 = largest1, num
            elif num >= largest2:
                largest2 = num

        return (largest1 * largest2) - (smallest1 * smallest2)

