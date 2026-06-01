from typing import Optional
from devlibs.singly_linkedlist import ListNode, printSinglyLinkList


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        n1 = head
        n2 = head

        for i in range(n):
            n2 = n2.next
        
        if (n2 == None):
            head = head.next
            return head

        while (n2.next != None):
            n2 = n2.next
            n1 = n1.next
            
        n1.next = n1.next.next
        
        return head


if __name__ == "__main__":
    solution = Solution()

    # Test Case 1:
    head1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    result1 = solution.removeNthFromEnd(head1, 2)
    printSinglyLinkList(result1)
    
    # Test Case 2:
    head2 = ListNode(1)
    result2 = solution.removeNthFromEnd(head2, 1)
    printSinglyLinkList(result2)

    
    # Test Case 3:
    head3 = ListNode(1, ListNode(2))
    result3 = solution.removeNthFromEnd(head3, 2)
    printSinglyLinkList(result3)

    