package main

import (
	"fmt"
	"sort"
)

// Past the function from leetcode here

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func gcdSum(nums []int) int64 {
	n := len(nums)

	prefix := make([]int, n)

	mx := 0
	for i, x := range nums {
		if x > mx {
			mx = x
		}
		prefix[i] = gcd(x, mx)
	}

	sort.Ints(prefix)

	var ans int64

	l, r := 0, n-1
	for l < r {
		ans += int64(gcd(prefix[l], prefix[r]))
		l++
		r--
	}

	return ans
}

func main() {
	// test cases 1
	nums := []int{2, 6, 4}
	fmt.Println(gcdSum(nums))

	// test cases 2
	nums = []int{3, 6, 2, 8}
	fmt.Println(gcdSum(nums))
}
