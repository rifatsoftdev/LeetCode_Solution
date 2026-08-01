package main

import "fmt"

// Past the function from leetcode here
func minimumPushes(word string) int {
	ans := 0

	for i := 0; i < len(word); i++ {
		ans += i/8 + 1
	}

	return ans
}

func main() {
	// test cases 1
	word1 := "abcde"
	fmt.Println(minimumPushes(word1))

	// test cases 2
	word2 := "xycdefghij"
	fmt.Println(minimumPushes(word2))

}
