# problem_name
- Difficulty: difficulty
- Link: https://leetcode.com/problems/

## 🧠 Approach
- Use two pointers: `i` for iterating through the array and `ans` for tracking the position to write non-target values.
- Iterate through the array with `i`, and if `nums[i]` is not equal to `val`, assign it to `nums[ans]` and increment `ans`.
- Return `ans` as the new length of the array after removing all occurrences of `val`.


## ⏳ Time Complexity
- O(n), where n is the length of the input array, as we iterate through the array once.

## 💾 Space Complexity
- O(1), as we only use two integer variables regardless of input size.
