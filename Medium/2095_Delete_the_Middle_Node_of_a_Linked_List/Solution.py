from typing import List, Optional
from devlibs.singly_linkedlist import ListNode, listToSinglyLinkedList, printSinglyLinkList


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (head == None or head.next == None):
            return None
        
        fast = head
        slow = head
        prev = head

        while (fast != None and fast.next != None):
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        prev.next = prev.next.next

        return head


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1: ListNode = listToSinglyLinkedList([1,3,4,7,1,2,6])
    ans1 = solution.deleteMiddle(head1)
    printSinglyLinkList(ans1)

    # test cases 2
    head1: ListNode = listToSinglyLinkedList([1,2,3,4])
    ans1 = solution.deleteMiddle(head1)
    printSinglyLinkList(ans1)

    # test cases 3
    head1: ListNode = listToSinglyLinkedList([2,1])
    ans1 = solution.deleteMiddle(head1)
    printSinglyLinkList(ans1)

