# problem_name
- Difficulty: difficulty
- Link: https://leetcode.com/problems/rotate-string/description/

## 🧠 Approach
- Rotate String:
    1. Iterate through all possible rotations of string `s` and check if any of them matches `goal`.
    2. For each rotation, create a new string by concatenating the substring from the current index to the end of `s` with the substring from the beginning of `s` to the current index.
    3. If any of the rotated strings matches `goal`, return true. If none of the rotations match, return false.


## ⏱ Time Complexity
- O(n^2) - where n is the length of the string `s`. We generate n rotations and each rotation takes O(n) time to create and compare.


## 💾 Space Complexity
- O(n) - for storing the rotated string in each iteration.
