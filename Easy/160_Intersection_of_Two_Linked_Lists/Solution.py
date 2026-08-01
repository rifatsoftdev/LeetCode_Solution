from typing import List, Optional
from devlibs.singly_linkedlist import ListNode


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
#         tmp = headA

#         while tmp:
#             tmpB = headB

#             while tmpB:
#                 if tmp is tmpB:
#                     return tmp

#                 tmpB = tmpB.next

#             tmp = tmp.next

#         return None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        a = headA
        b = headB

        while a is not b:
            a = a.next if a else headB
            b = b.next if b else headA

        return a


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    # test cases 2
    
    