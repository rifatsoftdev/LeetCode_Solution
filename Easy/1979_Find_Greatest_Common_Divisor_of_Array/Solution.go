package main

import (
	"fmt"
	"sort"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func findGCD(nums []int) int {
	sort.Ints(nums)
	return gcd(nums[0], nums[len(nums)-1])
}

func main() {
	// test cases 1
	nums := []int{2, 5, 6, 9, 10}
	fmt.Println(findGCD(nums))

	// test cases 2
	nums2 := []int{7, 5, 6, 8, 3}
	fmt.Println(findGCD(nums2))

	// test cases 3
	nums3 := []int{3, 3}
	fmt.Println(findGCD(nums3))
}
