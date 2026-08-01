# 88_Merge_Sorted_Array

## 🧠 Approach
- Use three pointers: `i` starting at `m-1`, `j` starting at `n-1`, and `idx` starting at `m+n-1`.
- Compare `nums1[i]` and `nums2[j]`, place the larger one at `nums1[idx]`, and decrement the corresponding pointers.
- If any elements remain in `nums2` after `nums1` is exhausted, copy them over.

## ⏳ Time Complexity
- O(m + n), where m and n are the lengths of nums1 and nums2 respectively, due to iterating through both arrays once.

## 💾 Space Complexity
- O(1), as the merging is done in-place using only a few integer variables for pointers.