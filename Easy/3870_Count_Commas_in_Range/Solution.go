package main

import "fmt"

// Past the function from leetcode here
func countCommas(n int) int {
	ans := n - 999

	if ans < 0 {
		return 0
	}

	return ans
}

func main() {
	// test cases 1
	n1 := 1002
	result1 := countCommas(n1)
	fmt.Println(result1)

	// test cases 2
	n2 := 999
	result2 := countCommas(n2)
	fmt.Println(result2)

}
