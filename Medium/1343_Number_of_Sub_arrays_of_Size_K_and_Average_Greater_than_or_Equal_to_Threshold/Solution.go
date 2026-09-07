package main

import "fmt"

// Past the function from leetcode here
func numOfSubarrays(arr []int, k int, threshold int) int {
	ans := 0
	sum := 0

	for i := 0; i < k; i++ {
		sum += arr[i]
	}

	if sum >= threshold*k {
		ans += 1
	}

	for i := k; i < len(arr); i++ {
		sum -= arr[i-k]
		sum += arr[i]

		if sum >= threshold*k {
			ans += 1
		}
	}

	return ans
}

func main() {
	// test cases 1
	arr1 := []int{2, 2, 2, 2, 5, 5, 5, 8}
	k1 := 3
	threshold1 := 4
	fmt.Println(numOfSubarrays(arr1, k1, threshold1))

	// test cases 2
	arr2 := []int{11, 13, 17, 23, 29, 31, 7, 5, 2, 3}
	k2 := 3
	threshold2 := 5
	fmt.Println(numOfSubarrays(arr2, k2, threshold2))
}
