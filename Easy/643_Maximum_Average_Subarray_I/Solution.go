package main

import "fmt"

// Past the function from leetcode here
func findMaxAverage(nums []int, k int) float64 {
	windowSum := 0
	for i := 0; i < k; i++ {
		windowSum += nums[i]
	}

	maxSum := windowSum
	for i := k; i < len(nums); i++ {
		windowSum += nums[i] - nums[i-k]
		if windowSum > maxSum {
			maxSum = windowSum
		}
	}

	return float64(maxSum) / float64(k)
}

func main() {
	// test cases 1
	nums1 := []int{1, 12, -5, -6, 50, 3}
	k1 := 4
	fmt.Println(findMaxAverage(nums1, k1))

	// test cases 2
	nums2 := []int{5}
	k2 := 1
	fmt.Println(findMaxAverage(nums2, k2))
}
