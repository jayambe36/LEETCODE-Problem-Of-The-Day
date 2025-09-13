class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels = set("aeiou")
        freq = [0] * 26

        max_vowel = 0
        max_consonant = 0

        for c in s:
            idx = ord(c) - ord('a')
            freq[idx] += 1

            if c in vowels:
                max_vowel = max(max_vowel, freq[idx])
            else:
                max_consonant = max(max_consonant, freq[idx])

        return max_vowel + max_consonant