package main

import (
	"fmt"
	"sort"
)

// Past the function from leetcode here
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	sort.Strings(strs)

	first := strs[0]
	last := strs[len(strs)-1]
	i := 0

	for i < len(first) && i < len(last) && first[i] == last[i] {
		i++
	}

	return first[:i]
}

func main() {
	// test cases 1
	strs1 := [3]string{"flower", "flow", "flight"}
	fmt.Println(longestCommonPrefix(strs1[:]))

	// test cases 2
	strs2 := [3]string{"dog", "racecar", "car"}
	fmt.Println(longestCommonPrefix(strs2[:]))
}
