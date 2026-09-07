package main

// Past the function from leetcode here
func kidsWithCandies(candies []int, extraCandies int) []bool {
	maxC := max(candies)
	result := make([]bool, len(candies))

	for i, c := range candies {
		result[i] = c+extraCandies >= maxC
	}

	return result
}

func max(arr []int) int {
	maxVal := arr[0]
	for _, v := range arr {
		if v > maxVal {
			maxVal = v
		}
	}
	return maxVal
}

func printVec(vec []bool) {
	for _, v := range vec {
		if v {
			print("true ")
		} else {
			print("false ")
		}
	}
	println()
}

func main() {
	// test cases 1
	candies1 := []int{2, 3, 5, 1, 3}
	extraCandies1 := 3
	result1 := kidsWithCandies(candies1, extraCandies1)
	printVec(result1)

	// test cases 2
	candies2 := []int{4, 2, 1, 1, 2}
	extraCandies2 := 1
	result2 := kidsWithCandies(candies2, extraCandies2)
	printVec(result2)

	// test cases 3
	candies3 := []int{12, 1, 12}
	extraCandies3 := 10
	result3 := kidsWithCandies(candies3, extraCandies3)
	printVec(result3)

}
