#include <cmath>

class Solution {
public:
    // Function to calculate the sum of squares of digits of a number
    int next(int x) {
        int y = 0;
        for (; x; x /= 10) {
            y += pow(x % 10, 2);
        }
        return y;
    }

    // Function to check if a number is a happy number
    bool isHappy(int n) {
        int slow = n, fast = next(n); // Initialize slow and fast pointers

        // Continue the loop until slow and fast pointers meet or slow becomes 1 (indicating a happy number)
        while (slow != fast) {
            slow = next(slow); // Move slow pointer by one step
            fast = next(next(fast)); // Move fast pointer by two steps
        }

        return slow == 1; // If slow becomes 1, it's a happy number; otherwise, it's not
    }
};
