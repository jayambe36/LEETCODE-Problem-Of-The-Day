class Solution {
public:
    bool halvesAreAlike(string s) {
        // Step 1: Initialize an unordered_set to store vowels (both lowercase and uppercase)
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        // Step 2: Calculate the midpoint of the input string
        int mid = s.length() / 2;

        // Step 3: Iterate through the first half and compare each character with the corresponding character in the second half
        int count = 0;
        for (int i = 0; i < mid; i++) {
            char a = s[i];                // Character from the first half
            char b = s[mid + i];          // Corresponding character from the second half
            
            // Increment count if the character from the first half is a vowel
            if (vowelSet.count(a)) {
                count++;
            }
            
            // Decrement count if the character from the second half is a vowel
            if (vowelSet.count(b)) {
                count--;
            }
        }

        // Step 4: Check if the count is zero, indicating an equal number of vowels in both halves
        return count == 0;
    }
};
