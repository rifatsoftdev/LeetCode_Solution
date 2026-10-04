package main

import (
	"fmt"
	"sort"
)

// Past the function from leetcode here
func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}

	s1Bytes := []byte(s1)
	sort.Slice(s1Bytes, func(i, j int) bool {
		return s1Bytes[i] < s1Bytes[j]
	})

	n := len(s1)

	for i := n; i <= len(s2); i++ {
		window := []byte(s2[i-n : i])

		sort.Slice(window, func(i, j int) bool {
			return window[i] < window[j]
		})

		if string(s1Bytes) == string(window) {
			return true
		}
	}

	return false
}

func main() {
	// test cases 1
	s11 := "ab"
	s21 := "eidbaooo"
	fmt.Println(checkInclusion(s11, s21))

	// test cases 2
	s12 := "ab"
	s22 := "eidboaoo"
	fmt.Println(checkInclusion(s12, s22))

}
