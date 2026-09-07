package main

import "fmt"

// Past the function from leetcode here
func largestOddNumber(num string) string {
	for i := len(num) - 1; i >= 0; i-- {
		if (num[i]-'0')%2 == 1 {
			return num[:i+1]
		}
	}

	return ""
}

func main() {
	// test cases 1
	num1 := "52"
	fmt.Println(largestOddNumber(num1)) // Output: "5"

	// test cases 2
	num2 := "4206"
	fmt.Println(largestOddNumber(num2)) // Output: ""

	// test cases 3
	num3 := "35427"
	fmt.Println(largestOddNumber(num3)) // Output: "35427"
}
