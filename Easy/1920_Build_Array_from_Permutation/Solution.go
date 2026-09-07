package main

import "fmt"

// Past the function from leetcode here
func buildArray(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)

	for i := 0; i < n; i++ {
		ans[i] = nums[nums[i]]
	}

	return ans
}

func main() {
	// test cases 1
	nums1 := []int{0, 2, 1, 5, 3, 4}
	result1 := buildArray(nums1)
	fmt.Println(result1)

	// test cases 2
	nums2 := []int{5, 0, 1, 2, 3, 4}
	result2 := buildArray(nums2)
	fmt.Println(result2)

}
