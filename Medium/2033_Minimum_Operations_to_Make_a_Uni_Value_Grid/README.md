# 2033. Minimum Operations to Make a Uni-Value Grid

## 🧠 Approach 1: Median-Based (Optimal)

1. Flatten the 2D grid into a 1D array.
2. Check feasibility:
   - For all elements, `(value - base) % x == 0` must hold.
   - If not, return `-1`.
3. Sort the array.
4. Select the median as the target value.
5. Compute total operations:
   - Sum of `abs(value - median) / x` for all elements.

### 💡 Key Insight
- The median minimizes the total absolute difference.
- All elements must belong to the same modulo class (mod x).

---

## 🧠 Approach 2: Brute Force Target Selection (Optional)

1. Flatten the grid into a 1D array.
2. Check feasibility using modulo condition.
3. For each element in the array:
   - Consider it as a target.
   - Compute total operations required to convert all elements to this target.
4. Return the minimum operations among all possible targets.

### 💡 Key Insight
- Tries all possible targets instead of directly choosing median.
- Less efficient but helps understand why median works.

---

## ⏱️ Complexity

### Approach 1:
- Time: `O(m * n * log(m * n))`
- Space: `O(m * n)`

### Approach 2:
- Time: `O((m * n)^2)`
- Space: `O(m * n)`