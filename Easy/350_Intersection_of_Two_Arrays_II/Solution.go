package main

import (
	"fmt"
	"sort"
)

// Past the function from leetcode here
func intersect(nums1 []int, nums2 []int) []int {
    sort.Ints(nums1)
    sort.Ints(nums2)
    i, j := 0, 0
    result := []int{}
    
    for i < len(nums1) && j < len(nums2) {
        if nums1[i] < nums2[j] {
            i++
        } else if nums1[i] > nums2[j] {
            j++
        } else {
            result = append(result, nums1[i])
            i++
            j++
        }
    }
    
    return result
}

func main() {
    // test cases 1
    nums1 := []int{1, 2, 2, 1}
    nums2 := []int{2, 2}
    result1 := intersect(nums1, nums2)
    fmt.Println(result1) // Expected output: [2, 2]

    // test cases 2
    nums3 := []int{4, 9, 5}
    nums4 := []int{9, 4, 9, 8, 4}
    result2 := intersect(nums3, nums4)
    fmt.Println(result2) // Expected output: [4, 9]
}
