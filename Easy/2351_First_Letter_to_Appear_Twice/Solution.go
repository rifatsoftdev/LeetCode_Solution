package main

import "fmt"

// Past the function from leetcode here
func repeatedCharacter(s string) byte {
	seen := make(map[rune]bool)

	for _, char := range s {
		if seen[char] {
			return byte(char)
		}
		seen[char] = true
	}

	return 0
}

func main() {
	// test cases 1
	s1 := "abccbaacz"
	fmt.Println(string(repeatedCharacter(s1)))

	// test cases 2
	s2 := "abcdd"
	fmt.Println(string(repeatedCharacter(s2)))
}
