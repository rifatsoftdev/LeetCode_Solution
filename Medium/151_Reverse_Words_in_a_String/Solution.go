package main

import (
	"fmt"
	"strings"
)

func reverseWords(s string) string {
	words := strings.Fields(s)

	for i, j := 0, len(words)-1; i < j; i, j = i+1, j-1 {
		words[i], words[j] = words[j], words[i]
	}

	return strings.Join(words, " ")
}

func main() {
	// test cases 1
	s1 := "the sky is blue"
	fmt.Println(reverseWords(s1)) // Output: "blue is sky the"

	// test cases 2
	s2 := "  hello world  "
	fmt.Println(reverseWords(s2)) // Output: "world hello"
}
