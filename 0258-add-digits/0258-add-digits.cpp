class Solution {
public:
    int addDigits(int n) {
        // If n is 0, the result is 0
        if (n == 0) {
            return 0;
        } else {
            // Applying the digital root algorithm:
            // If n is divisible by 9, the result is 9
            if (n % 9 == 0) {
                return 9;
            } else {
                // Otherwise, the result is the remainder when n is divided by 9
                return n % 9;
            }
        }
    }
};