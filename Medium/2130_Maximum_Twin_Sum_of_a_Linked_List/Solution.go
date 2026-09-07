package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

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

func createSinglyLinkedList(values []int) *ListNode {
	if len(values) == 0 {
		return nil
	}

	head := &ListNode{Val: values[0]}
	curr := head

	for i := 1; i < len(values); i++ {
		curr.Next = &ListNode{Val: values[i]}
		curr = curr.Next
	}

	return head
}

func main() {
	// test cases 1
	head1 := createSinglyLinkedList([]int{5, 4, 2, 1})
	fmt.Println(pairSum(head1))

	// test cases 2
	head2 := createSinglyLinkedList([]int{4, 2, 2, 3})
	fmt.Println(pairSum(head2))

	// test cases 3
	head3 := createSinglyLinkedList([]int{1, 100000})
	fmt.Println(pairSum(head3))
}
