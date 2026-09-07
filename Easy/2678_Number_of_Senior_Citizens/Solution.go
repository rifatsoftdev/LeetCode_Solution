package main

import "fmt"

// Past the function from leetcode here
func countSeniors(details []string) int {
	count := 0

	for _, detail := range details {
		age := detail[11:13]
		if age > "60" {
			count++
		}
	}

	return count
}

func main() {
	// test cases 1
	details1 := []string{"7868190130M7522", "5303914400F9211", "9273338290F4010"}
	fmt.Println(countSeniors(details1)) // Output: 2

	// test cases 2
	details2 := []string{"1313579440F2036", "2921522980M5644"}
	fmt.Println(countSeniors(details2)) // Output: 0

}
