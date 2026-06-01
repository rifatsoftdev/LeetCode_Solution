from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = head
        slow = head

        while ((fast != None) and (fast.next != None)):
            fast = fast.next.next
            slow = slow.next
        
        return slow


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    result1 = solution.middleNode(head1)
    print(result1.val)

    # test cases 2
    head2 = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, ListNode(6))))))
    result2 = solution.middleNode(head2)
    print(result2.val)
    