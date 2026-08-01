package main

import "fmt"

// Past the function from leetcode here
func smallestEvenMultiple(n int) int {
	if n%2 == 0 {
		return n
	}
	return n * 2
}

func main() {
	// test cases 1
	fmt.Println(smallestEvenMultiple(5)) // Expected: 10

	// test cases 2
	fmt.Println(smallestEvenMultiple(6)) // Expected: 6
}
