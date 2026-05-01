# 169_Majority_Element

```
Majority Element:
    1. Use a hash map to store the frequency of each element in the array.
    2. Iterate through the array and increment the count for each element in the map.
    3. For each element, check if its count has reached the majority threshold (n/2).
    4. Return the element that meets the majority criteria.

Time Complexity: O(n) (where n is the number of elements in the array)
Space Complexity: O(n) (to store the frequencies in the map)

Note: This problem can also be solved in O(1) space using Boyer-Moore Voting Algorithm.
```

```
Boyer-Moore Voting Algorithm:
    1. Initialize a candidate `ans` and a counter `freq` to 0.
    2. Iterate through the array:
        a. If `freq` is 0, set the current element as the candidate `ans`.
        b. If the current element is the same as `ans`, increment `freq`.
        c. Otherwise, decrement `freq`.
    3. The candidate remaining at the end is the majority element.

Time Complexity: O(n)
Space Complexity: O(1)
```