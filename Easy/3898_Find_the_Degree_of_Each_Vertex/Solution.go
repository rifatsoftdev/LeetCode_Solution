package main

import "fmt"

// Past the function from leetcode here
func findDegrees(matrix [][]int) []int {
	n := len(matrix)
	result := make([]int, n)

	for i := 0; i < n; i++ {
		tmp := 0

		for j := 0; j < len(matrix[i]); j++ {
			tmp += matrix[i][j]
		}

		result[i] = tmp
	}

	return result
}

func main() {
	// test cases 1
	matrix1 := [][]int{{0, 1, 1}, {1, 0, 1}, {1, 1, 0}}
	result1 := findDegrees(matrix1)
	fmt.Println(result1)

	// test cases 2
	matrix2 := [][]int{{0, 1, 0}, {1, 0, 0}, {0, 0, 0}}
	result2 := findDegrees(matrix2)
	fmt.Println(result2)

	// test cases 3
	matrix3 := [][]int{{0}}
	result3 := findDegrees(matrix3)
	fmt.Println(result3)

}
