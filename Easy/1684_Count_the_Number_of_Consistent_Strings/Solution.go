package main

import "fmt"

// Past the function from leetcode here
func countConsistentStrings(allowed string, words []string) int {
	arr := make([]bool, 26)

	for _, c := range allowed {
		arr[c-'a'] = true
	}

	result := 0

	for _, s := range words {
		flag := true

		for _, c := range s {
			if !arr[c-'a'] {
				flag = false
				break
			}
		}

		if flag {
			result++
		}
	}

	return result
}

func main() {
	// test case 1
	allowed1 := "ab"
	words1 := []string{"ad", "bd", "aaab", "baa", "badab"}

	fmt.Println(countConsistentStrings(allowed1, words1))

	// test case 2
	allowed2 := "abc"
	words2 := []string{"a", "b", "c", "ab", "ac", "bc", "abc"}

	fmt.Println(countConsistentStrings(allowed2, words2))

	// test case 3
	allowed3 := "cad"
	words3 := []string{"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"}

	fmt.Println(countConsistentStrings(allowed3, words3))

}
