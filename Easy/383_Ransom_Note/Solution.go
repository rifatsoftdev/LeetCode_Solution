package main

import (
	"fmt"
)

func canConstruct(ransomNote string, magazine string) bool {
	freq := [26]int{}

	for _, c := range magazine {
		freq[c-'a']++
	}

	for _, c := range ransomNote {
		freq[c-'a']--

		if freq[c-'a'] < 0 {
			return false
		}
	}

	return true
}

func main() {
	// test cases 1
	ransomNote1 := "a"
	magazine1 := "b"
	fmt.Println(canConstruct(ransomNote1, magazine1))

	// test cases 2
	ransomNote2 := "aa"
	magazine2 := "ab"
	fmt.Println(canConstruct(ransomNote2, magazine2))

	// test cases 3
	ransomNote3 := "aa"
	magazine3 := "aab"
	fmt.Println(canConstruct(ransomNote3, magazine3))
}
