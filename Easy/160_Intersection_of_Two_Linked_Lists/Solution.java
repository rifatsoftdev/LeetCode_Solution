




public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        for (ListNode tmp = headA; tmp != null; tmp = tmp.next) {
            for (ListNode tmpB = headB; tmpB != null; tmpB = tmpB.next) {
                if (tmp == tmpB) {
                    return tmp;
                }
            }
        }

        return null;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        // test cases 2
        
        
    }
}


// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}