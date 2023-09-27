class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        length = 0  # Initialize a variable to keep track of the length of the decoded string.
        s0 = 0  # Initialize a variable to store the index where decoding begins.

        # Loop through the characters in the input string 's' using enumerate to get both index and character.
        for i, c in enumerate(s):
            if c.isalpha():  # If the character is an alphabet (letter):
                length += 1  # Increase the length of the decoded string by 1.
                if k == length:  # If the current length is equal to the target 'k':
                    return c  # Return the current character as it's the result.
            else:  # If the character is a digit (number):
                length *= int(c)  # Multiply the current length by the numeric value of the digit.

            if k <= length:  # If the target 'k' is less than or equal to the current length:
                s0 = i  # Store the current index as the starting point for the next loop.
                break

        # Loop backward from the starting point to the beginning of the string.
        for i in range(s0, -1, -1):
            c = s[i]
            k %= length  # Take the modulo of 'k' with the current length.
            if k == 0 and c.isalpha():  # If 'k' becomes 0 and the character is an alphabet:
                return c  # Return the current character as it's the result.
            if c.isdigit():  # If the character is a digit (number):
                length //= int(c)  # Divide the current length by the numeric value of the digit.
            else:  # If the character is not a digit (e.g., a special character):
                length -= 1  # Subtract 1 from the current length.

        return "X" 
