package main

import (
	"fmt"
	"sort"
)

func findLucky(arr []int) int {
	mp := make(map[int]int)

	for _, v := range arr {
		mp[v]++
	}

	sort.Ints(arr)

	for i := len(arr) - 1; i >= 0; i-- {
		if mp[arr[i]] == arr[i] {
			return arr[i]
		}
	}

	return -1
}

func main() {
	// test cases 1
	arr := []int{2, 2, 3, 4}
	fmt.Println(findLucky(arr)) // Output: 2

	// test cases 2
	arr = []int{1, 2, 2, 3, 3, 3}
	fmt.Println(findLucky(arr)) // Output: 3

	// test cases 3
	arr = []int{2, 2, 2, 3, 3}
	fmt.Println(findLucky(arr)) // Output: -1

}
