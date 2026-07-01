


// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}


public class Solution {
    public ListNode revListNode(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode tmp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

    public int pairSum(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        ListNode secondHalf = revListNode(slow);
        ListNode firstHalf = head;
        int maxVal = 0;

        while (secondHalf != null) {
            maxVal = Math.max(maxVal, firstHalf.val + secondHalf.val);
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }

        return maxVal;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        ListNode head1 = new ListNode(5, new ListNode(4, new ListNode(2, new ListNode(1))));
        System.out.println(solution.pairSum(head1)); // Expected: 6
        
        // test cases 2
        ListNode head2 = new ListNode(4, new ListNode(2, new ListNode(2, new ListNode(3))));
        System.out.println(solution.pairSum(head2)); // Expected: 7

        // test cases 3
        ListNode head3 = new ListNode(1, new ListNode(100000));
        System.out.println(solution.pairSum(head3)); // Expected: 100001
        
    }
}