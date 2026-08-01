# 383_Ransom_Note

/* ================================================================================
Solution 1:

Ransom Note:
    1. Count the frequency of each character in the `magazine` string using a hash map or a frequency array.
    2. Iterate through the `ransomNote` string and for each character, check if it exists in the frequency map with a count greater than zero.
    3. If the character is available, decrement its count in the map.
    4. If a character is not available or its count is zero, return false.
    5. If all characters in the `ransomNote` are successfully matched, return true.

Time Complexity: O(m + n), where m is the length of the ransomNote and n is the length of the magazine.
Space Complexity: O(k), where k is the number of unique characters (at most 26 for lowercase English letters).
*/