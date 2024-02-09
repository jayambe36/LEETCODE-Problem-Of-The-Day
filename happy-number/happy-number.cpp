#include <unordered_set>

class Solution {
public:
    // Function to check if a number is a happy number
    bool isHappy(int n) {
        unordered_set<int> vis; // Set to keep track of visited numbers

        // Continue the loop until n becomes 1 (happy number) or we encounter a cycle
        while (n != 1 && !vis.count(n)) {
            vis.insert(n); // Insert the current number into the set
            int x = 0; // Initialize a variable to store the sum of squares of digits

            // Calculate the sum of squares of digits of the current number
            for (; n; n /= 10) {
                x += (n % 10) * (n % 10);
            }
            n = x; // Update n with the sum of squares of digits
        }

        return n == 1; // If n becomes 1, it's a happy number; otherwise, it's not
    }
};
