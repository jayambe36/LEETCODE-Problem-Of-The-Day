class Solution:
    def countVowelPermutation(self, n: int) -> int:
        # Base case: there are 5 single character permutations (A, E, I, O, U) for n=1
        if n == 1:
            return 5
        # Initialize variables for each vowel count, and set the modulo value        
        a = e = i = o = u = 1
        mod = 10**9 + 7

        # Calculate the count of permutations for n > 1
        for _ in range(2, n + 1):
            # Update counts based on the rules for each vowel
            new_a = (e + u + i) % mod
            new_e = (a + i) % mod
            new_i = (e + o) % mod
            new_o = i
            new_u = (i + o) % mod
            # Update counts for the next iteration
            a, e, i, o, u = new_a, new_e, new_i, new_o, new_u

        return (a + e + i + o + u) % mod 
