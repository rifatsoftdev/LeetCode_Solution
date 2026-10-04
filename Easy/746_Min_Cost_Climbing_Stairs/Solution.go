package main

import "fmt"

// Past the function from leetcode here
func minCostClimbingStairs(cost []int) int {
	n := len(cost)

	dp := make([]int, n+1)

	dp[0] = 0
	dp[1] = 0

	for i := 2; i <= n; i++ {
		dp[i] = min(
			dp[i-1]+cost[i-1],
			dp[i-2]+cost[i-2],
		)
	}

	return dp[n]
}

func main() {
	// test cases 1
	cost1 := []int{10, 15, 20}
	result1 := minCostClimbingStairs(cost1)
	fmt.Println(result1)

	// test cases 2
	cost2 := []int{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}
	result2 := minCostClimbingStairs(cost2)
	fmt.Println(result2)
}
