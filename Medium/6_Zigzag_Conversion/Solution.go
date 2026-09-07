package main

import "fmt"

// Past the function from leetcode here
func convert(s string, numRows int) string {
	if numRows == 1 || numRows >= len(s) {
		return s
	}

	rows := make([]string, numRows)
	currentRow := 0
	goingDown := false

	for _, char := range s {
		rows[currentRow] += string(char)

		if currentRow == 0 || currentRow == numRows-1 {
			goingDown = !goingDown
		}

		if goingDown {
			currentRow++
		} else {
			currentRow--
		}
	}

	result := ""

	for _, row := range rows {
		result += row
	}

	return result
}

func main() {
	// test cases 1
	s1 := "PAYPALISHIRING"
	numRows1 := 3
	fmt.Println(convert(s1, numRows1)) // Output: "PAHNAPLSIIGYIR"

	// test cases 2
	s2 := "PAYPALISHIRING"
	numRows2 := 4
	fmt.Println(convert(s2, numRows2)) // Output: "PINALSIGYAHRPI"

	// test cases 3
	s3 := "A"
	numRows3 := 1
	fmt.Println(convert(s3, numRows3)) // Output: "A"

}
