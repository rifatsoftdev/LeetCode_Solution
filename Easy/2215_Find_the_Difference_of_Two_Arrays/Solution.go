package main

import "fmt"

// Past the function from leetcode here
func findDifference(nums1 []int, nums2 []int) [][]int {
	set1 := make(map[int]bool)
	set2 := make(map[int]bool)

	for _, num := range nums1 {
		set1[num] = true
	}

	for _, num := range nums2 {
		set2[num] = true
	}

	ans1 := []int{}
	ans2 := []int{}

	for num := range set1 {
		if !set2[num] {
			ans1 = append(ans1, num)
		}
	}

	for num := range set2 {
		if !set1[num] {
			ans2 = append(ans2, num)
		}
	}

	return [][]int{ans1, ans2}
}

func main() {
	// test cases 1
	nums1 := []int{1, 2, 3}
	nums2 := []int{2, 4, 6}
	result := findDifference(nums1, nums2)
	fmt.Println(result)

	// test cases 2
	nums3 := []int{1, 2, 3, 3}
	nums4 := []int{1, 1, 2, 2}
	result = findDifference(nums3, nums4)
	fmt.Println(result)
}
