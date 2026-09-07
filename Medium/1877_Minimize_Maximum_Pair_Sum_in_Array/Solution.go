package main

import "sort"

// Past the function from leetcode here
func minPairSum(nums []int) int {
	sort.Ints(nums)
	maxPairSum := 0
	n := len(nums)

	for i := 0; i < n/2; i++ {
		pairSum := nums[i] + nums[n-1-i]
		if pairSum > maxPairSum {
			maxPairSum = pairSum
		}
	}

	return maxPairSum
}

func main() {
	// test cases 1
	nums1 := []int{3, 5, 2, 3}
	println(minPairSum(nums1)) // Output: 7

	// test cases 2
	nums2 := []int{3, 5, 4, 2, 4, 6}
	println(minPairSum(nums2)) // Output: 8
}
