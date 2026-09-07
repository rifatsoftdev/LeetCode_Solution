package main

import "fmt"

// Past the function from leetcode here
func convertTemperature(celsius float64) []float64 {
	kelvin := celsius + 273.15
	fahrenheit := celsius*1.80 + 32.00

	return []float64{kelvin, fahrenheit}
}

func main() {
	// test cases 1
	celsius1 := 36.50
	result1 := convertTemperature(celsius1)
	fmt.Println(result1)

	// test cases 2
	celsius2 := 122.11
	result2 := convertTemperature(celsius2)
	fmt.Println(result2)

}
