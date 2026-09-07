package main

import "fmt"

// Past the function from leetcode here
func mergeAlternately(word1 string, word2 string) string {
	m := len(word1)
	n := len(word2)
	result := make([]byte, 0, m+n)
	i, j := 0, 0

	for i < m && j < n {
		result = append(result, word1[i])
		result = append(result, word2[j])
		i++
		j++
	}

	for i < m {
		result = append(result, word1[i])
		i++
	}

	for j < n {
		result = append(result, word2[j])
		j++
	}

	return string(result)
}

func main() {
	// test cases 1
	word1 := "abc"
	word2 := "pqr"
	result := mergeAlternately(word1, word2)
	fmt.Println(result) // Expected: "apbqcr"

	// test cases 2
	word1 = "ab"
	word2 = "pqrs"
	result = mergeAlternately(word1, word2)
	fmt.Println(result) // Expected: "apbqcr"

	// test cases 3
	word1 = "abcd"
	word2 = "pq"
	result = mergeAlternately(word1, word2)
	fmt.Println(result) // Expected: "apbqcr"

}
