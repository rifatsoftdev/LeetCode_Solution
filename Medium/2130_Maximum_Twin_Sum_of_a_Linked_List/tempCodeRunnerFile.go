func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	curr := head

	for curr != nil {
		tmp := curr.Next
		curr.Next = prev
		prev = curr
		curr = tmp
	}

	return prev
}

func pairSum(head *ListNode) int {
	slow := head
	fast := head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	secondHalf := reverseList(slow)

	maxSum := 0

	firstHalf := head

	for secondHalf != nil {
		sum := firstHalf.Val + secondHalf.Val

		if sum > maxSum {
			maxSum = sum
		}

		firstHalf = firstHalf.Next
		secondHalf = secondHalf.Next
	}

	return maxSum
}