# 1342_Number_of_Steps_to_Reduce_a_Number_to_Zero

/* ================================================================================
Solution 1:

Number of Steps to Reduce a Number to Zero:
    1. Initialize a `steps` counter to 0.
    2. While the number `num` is greater than 0:
        a. If `num` is even, divide it by 2.
        b. If `num` is odd, subtract 1 from it.
        c. Increment the `steps` counter after each operation.
    3. Return the total number of steps taken to reach zero.

Time Complexity: O(log n), as dividing by 2 reduces the number of bits in each step.
Space Complexity: O(1), as we only use a single integer variable for counting.
*/