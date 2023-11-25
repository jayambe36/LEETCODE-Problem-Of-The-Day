class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix_sum = [0] * n
        suffix_sum = [0] * n

        # Calculate prefix sum
        prefix_sum[0] = nums[0]
        for i in range(1, n):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i]

        # Calculate suffix sum
        suffix_sum[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            suffix_sum[i] = suffix_sum[i + 1] + nums[i]

        result = []
        for i in range(n):
            # Calculate left and right sums efficiently using prefix and suffix sums
            left_sum = i * nums[i] - prefix_sum[i]
            right_sum = suffix_sum[i] - (n - i - 1) * nums[i]

            # Calculate the total sum of absolute differences
            result.append(left_sum + right_sum)

        return result
