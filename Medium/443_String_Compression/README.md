# 443_String_Compression

/* ================================================================================
Solution 1:

String Compression:
    1. Iterate through the input character array to identify groups of consecutive identical characters.
    2. For each group, append the character to a result string.
    3. If the group's length is greater than 1, append the length as a string to the result.
    4. Modify the original `chars` array in-place using the characters from the result string.
    5. Return the length of the compressed string.

Time Complexity: O(n) where n is the length of the input array.
Space Complexity: O(n) to store the intermediate compressed string.
*/