# 9_Palindrome_Number


```
Palindrome Number (Reversing the Integer):
    1. If the number is negative, it cannot be a palindrome (e.g., -121 becomes 121-).
    2. Reverse the digits of the integer.
    3. Compare the reversed integer with the original integer. If they are equal, the number is a palindrome.

Time Complexity: O(log10(n)), where n is the input integer. We iterate through the digits of the number.
Space Complexity: O(1), as we only use a few variables to store the reversed number and temporary values.
```
