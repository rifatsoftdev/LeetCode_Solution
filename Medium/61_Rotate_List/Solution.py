from typing import Optional
from devlibs import printSinglyLinkList


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if (not head or not head.next or k == 0):
            return head
            
        len =  0
        curr = head

        while (curr != None):
            curr = curr.next
            len += 1
        
        rotate = k % len

        if (rotate == 0):
            return head

        slow = head
        fast = head

        for i in range(rotate):
            fast = fast.next
        
        while (fast.next):
            fast = fast.next
            slow = slow.next
        
        newHead = slow.next
        slow.next = None
        fast.next = head

        return newHead


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    ans1 = solution.rotateRight(head1, 2)
    printSinglyLinkList(ans1)

    # test cases 2
    head2 = ListNode(0, ListNode(1, ListNode(2)))
    ans2 = solution.rotateRight(head2, 4)
    printSinglyLinkList(ans2)

