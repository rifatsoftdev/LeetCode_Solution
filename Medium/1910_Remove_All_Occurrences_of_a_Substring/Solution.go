package main

import (
	"fmt"
	"strings"
)

// Past the function from leetcode here
func removeOccurrences(s string, part string) string {
	for strings.Contains(s, part) {
		pos := strings.Index(s, part)

		s = s[:pos] + s[pos+len(part):]
	}

	return s
}

func main() {
	// test cases 1
	s1 := "daabcbaabcbc"
	part1 := "abc"
	fmt.Println(removeOccurrences(s1, part1))

	// test cases 2
	s2 := "axxxxyyyyb"
	part2 := "xy"
	fmt.Println(removeOccurrences(s2, part2))

}
