package main

import "fmt"

// Past the function from leetcode here
func finalValueAfterOperations(operations []string) int {
	ans := 0

	for _, operation := range operations {
		if operation == "++X" || operation == "X++" {
			ans++
		} else if operation == "--X" || operation == "X--" {
			ans--
		}
	}

	return ans
}

func main() {
	// test cases 1
	operations1 := [...]string{"--X", "X++", "X++"}
	result1 := finalValueAfterOperations(operations1[:])
	fmt.Println(result1) // Output: 1

	// test cases 2
	operations2 := [...]string{"++X", "++X", "X++"}
	result2 := finalValueAfterOperations(operations2[:])
	fmt.Println(result2) // Output: 3

	// test cases 3
	operations3 := [...]string{"X++", "++X", "--X", "X--"}
	result3 := finalValueAfterOperations(operations3[:])
	fmt.Println(result3) // Output: 0
}
