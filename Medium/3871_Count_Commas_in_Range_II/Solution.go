package main

import "fmt"

// Past the function from leetcode here
func countCommas(n int64) int64 {
	var ans int64 = 0

	for i := int64(1000); i <= n; i *= 1000 {
		ans += (n - i + 1)
	}

	return ans
}

func main() {
	// test cases 1
	n1 := int64(1002)
	result1 := countCommas(n1)
	fmt.Println(result1)

	// test cases 2
	n2 := int64(998)
	result2 := countCommas(n2)
	fmt.Println(result2)

}
