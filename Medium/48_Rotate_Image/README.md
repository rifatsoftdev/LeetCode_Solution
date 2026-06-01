# 48_Rotate_Image

Optimal Solution (Transpose and Reverse):
    1. To rotate the image by 90 degrees clockwise, we can first transpose the matrix.
    2. Transposing involves swapping elements at `matrix[i][j]` with `matrix[j][i]`.
    3. After transposing, we reverse each row of the matrix to achieve the 90-degree rotation.

Time Complexity: O(n^2) - We traverse the matrix twice (once for transpose and once for reversing rows).
Space Complexity: O(1) - The rotation is performed in-place.