package main

import "fmt"

// Past the function from leetcode here
func sumZero(n int) []int {
	result := []int{}

	if n%2 == 1 {
		result = append(result, 0)
	}

	for i := 1; i <= n/2; i++ {
		result = append(result, i)
		result = append(result, -i)
	}

	return result
}

func main() {
	// test cases 1
	n := 5
	result := sumZero(n)
	fmt.Println(result) // Output: [0, 1, -1, 2, -2]

	// test cases 2
	n = 3
	result = sumZero(n)
	fmt.Println(result) // Output: [0, 1, -1]

	// test cases 3
	n = 1
	result = sumZero(n)
	fmt.Println(result) // Output: [0]

}
