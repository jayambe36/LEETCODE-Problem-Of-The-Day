class Solution:
    def isHappy(self, n: int) -> bool:
        # Function to calculate the sum of squares of digits of a number
        def next(x):
            y = 0
            while x:
                x, v = divmod(x, 10)  # Dividing the number by 10 and getting quotient and remainder
                y += v * v  # Adding the square of the remainder to y
            return y

        # Initialize slow and fast pointers
        slow, fast = n, next(n)

        # Continue the loop until slow and fast pointers meet or slow becomes 1 (indicating a happy number)
        while slow != fast:
            slow = next(slow)  # Move slow pointer by one step
            fast = next(next(fast))  # Move fast pointer by two steps

        return slow == 1  # If slow becomes 1, it's a happy number; otherwise, it's not
