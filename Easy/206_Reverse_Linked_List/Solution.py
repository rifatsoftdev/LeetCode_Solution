from typing import Optional
from devlibs import printSinglyLinkList


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head

        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        
        return prev


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    reversed_head1 = solution.reverseList(head1)
    printSinglyLinkList(reversed_head1)

    # test cases 2
    head2 = ListNode(1, ListNode(2))
    reversed_head2 = solution.reverseList(head2)
    printSinglyLinkList(reversed_head2)

    # test cases 3
    head3 = None
    reversed_head3 = solution.reverseList(head3)
    printSinglyLinkList(reversed_head3)
    