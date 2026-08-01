# 58_Length_of_Last_Word

/* ================================================================================
Solution 1:

Length of Last Word:
    1. Start iterating from the end of the string to find the last word.
    2. Skip any trailing spaces at the end of the string.
    3. Once a non-space character is encountered, start counting the characters until another space or the beginning of the string is reached.
    4. Return the count, which represents the length of the last word.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as we only use a single counter variable.
*/