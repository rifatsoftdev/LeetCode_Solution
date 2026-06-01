

public class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode smaller = new ListNode(0);
        ListNode larger = new ListNode(0);

        ListNode smallerHead = smaller;
        ListNode largerHead = larger;

        while (head != null) {
            if (head.val < x) {
                smaller.next = head;
                smaller = smaller.next;
            } else {
                larger.next = head;
                larger = larger.next;
            }
            head = head.next;
        }

        larger.next = null;
        smaller.next = largerHead.next;

        return smallerHead.next;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        ListNode head1 = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
        ListNode result1 = solution.partition(head1, 3);
        ListNode current1 = result1;
        while (current1 != null) {
            System.out.print(current1.val + " ");
            current1 = current1.next;
        }
        System.out.println();

        // test cases 2
        ListNode head2 = new ListNode(2, new ListNode(1));
        ListNode result2 = solution.partition(head2, 2);
        ListNode current2 = result2;
        while (current2 != null) {
            System.out.print(current2.val + " ");
            current2 = current2.next;
        }
        System.out.println();
        
    }
}

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}