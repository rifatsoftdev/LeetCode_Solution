package main

import (
	"fmt"
	"math"
)

// Past the function from leetcode here
func judgeSquareSum(c int) bool {
	left := 0
	right := int(math.Sqrt(float64(c)))

	for left <= right {
		sum := left*left + right*right
		if sum == c {
			return true
		} else if sum < c {
			left++
		} else {
			right--
		}
	}
	return false
}

func main() {
	// test cases 1
	fmt.Println(judgeSquareSum(5)) // true

	// test cases 2
	fmt.Println(judgeSquareSum(3)) // false
}
