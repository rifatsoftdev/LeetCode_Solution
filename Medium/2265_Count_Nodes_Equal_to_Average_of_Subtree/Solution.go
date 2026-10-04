package main

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// Past the function from leetcode here

func dfs(node *TreeNode) (int, int) {
	if node == nil {
		return 0, 0
	}

	leftSum, leftCount := dfs(node.Left)
	rightSum, rightCount := dfs(node.Right)

	totalSum := leftSum + rightSum + node.Val
	totalCount := leftCount + rightCount + 1

	return totalSum, totalCount
}

func averageOfSubtree(root *TreeNode) int {
	count := 0

	var dfs func(*TreeNode) (int, int)

	dfs = func(node *TreeNode) (int, int) {
		if node == nil {
			return 0, 0
		}

		leftSum, leftCount := dfs(node.Left)
		rightSum, rightCount := dfs(node.Right)

		totalSum := leftSum + rightSum + node.Val
		totalCount := leftCount + rightCount + 1

		// Check average
		if node.Val == totalSum/totalCount {
			count++
		}

		return totalSum, totalCount
	}

	dfs(root)

	return count
}

func main() {
	// test cases 1

	// test cases 2

}
