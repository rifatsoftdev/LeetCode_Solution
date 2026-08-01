package main

import (
	"fmt"
	"sort"
)

// Past the function from leetcode here
func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)

	n := len(nums)
	ans := [][]int{}

	for i := 0; i < n-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < n-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}

			k := j + 1
			l := n - 1

			for k < l {
				sum := int64(nums[i]) + int64(nums[j]) + int64(nums[k]) + int64(nums[l])

				if sum < int64(target) {
					k++
				} else if sum > int64(target) {
					l--
				} else {
					ans = append(ans, []int{nums[i], nums[j], nums[k], nums[l]})

					k++
					l--

					for k < l && nums[k] == nums[k-1] {
						k++
					}

					for k < l && nums[l] == nums[l+1] {
						l--
					}
				}
			}
		}
	}

	return ans
}

func main() {
	// Test case 1
	nums1 := []int{1, 0, -1, 0, -2, 2}
	ans1 := fourSum(nums1, 0)
	fmt.Println(ans1)

	// Test case 2
	nums2 := []int{2, 2, 2, 2, 2}
	ans2 := fourSum(nums2, 8)
	fmt.Println(ans2)
}
