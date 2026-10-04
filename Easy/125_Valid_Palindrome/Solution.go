package main

import "fmt"

// Past the function from leetcode here
func isPalindrome(s string) bool {
	left := 0
	right := len(s) - 1

	for left < right {
		if !isAlphaNumeric(s[left]) {
			left++
		} else if !isAlphaNumeric(s[right]) {
			right--
		} else {
			if toLower(s[left]) != toLower(s[right]) {
				return false
			}

			left++
			right--
		}
	}

	return true
}

func isAlphaNumeric(c byte) bool {
	return (c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9')
}

func toLower(c byte) byte {
	if c >= 'A' && c <= 'Z' {
		return c + ('a' - 'A')
	}

	return c
}

func main() {
	// test cases 1
	s1 := "A man, a plan, a canal: Panama"
	fmt.Println(isPalindrome(s1))

	// test cases 2
	s2 := "race a car"
	fmt.Println(isPalindrome(s2))

	// test cases 3
	s3 := " "
	fmt.Println(isPalindrome(s3))
}
