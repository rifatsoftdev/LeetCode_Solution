package main

import "fmt"

// Past the function from leetcode here
func intersection(nums [][]int) []int {
	n := len(nums)
	count := make([]int, 1001)

	for _, arr := range nums {
		seen := make(map[int]bool)
		for _, num := range arr {
			if !seen[num] {
				count[num]++
				seen[num] = true
			}
		}
	}

	result := []int{}

	for i := 0; i <= 1000; i++ {
		if count[i] == n {
			result = append(result, i)
		}
	}

	return result
}

func main() {
	// test cases 1
	nums1 := [][]int{{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}}
	result1 := intersection(nums1)
	fmt.Println(result1) // Output: [3, 4]

	// test cases 2
	nums2 := [][]int{{1, 2, 3}, {4, 5, 6}}
	result2 := intersection(nums2)
	fmt.Println(result2) // Output: []

}
