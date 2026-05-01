# 01_Two_Sum

```text
Brute Force Approach (Linear Search):
    1. Iterate through the array and check for each element if it has a duplicate.
    2. Return the element that does not have a duplicate.

Time Complexity: O(n^2)
Space Complexity: O(1)
```


```text
Optimal Approach (Hash Map):
    1. Use an unordered_map to store the indices of the elements we have seen so far.
    2. For each element, calculate its complement (target - current element) and check if it exists in the map.
    3. If it exists, return the indices of the current element and its complement.
    4. If it does not exist, add the current element and its index to the map.

Time Complexity: O(n)
Space Complexity: O(n)
```