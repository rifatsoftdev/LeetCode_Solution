package main

import "fmt"

// Past the function from leetcode here
func sumOfSquares(nums []int) int {
	n := len(nums)
	ans := 0

	for i := 0; i < n; i++ {
		if n%(i+1) == 0 {
			ans += nums[i] * nums[i]
		}
	}

	return ans
}

func main() {
	// test cases 1
	nums1 := []int{1, 2, 3, 4}
	fmt.Println(sumOfSquares(nums1))

	// test cases 2
	nums2 := []int{2, 7, 1, 19, 18, 3}
	fmt.Println(sumOfSquares(nums2))

}
