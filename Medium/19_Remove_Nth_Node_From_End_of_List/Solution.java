


class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode n1 = head;
        ListNode n2 = head;

        for (int i = 0; i < n; i++) {
            n2 = n2.next;
        }

        if (n2 == null) {
            head = head.next;
            return head;
        }

        while (n2.next != null) {
            n2 = n2.next;
            n1 = n1.next;
        }

        n1.next = n1.next.next;

        return head;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        ListNode head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        int n1_val = 2;
        ListNode result1 = solution.removeNthFromEnd(head1, n1_val);
        while (result1 != null) {
            System.out.print(result1.val + " ");
            result1 = result1.next;
        }
        System.out.println();

        // test cases 2
        ListNode head2 = new ListNode(1);
        int n2_val = 1;
        ListNode result2 = solution.removeNthFromEnd(head2, n2_val);
        if (result2 == null) System.out.print("[]");
        while (result2 != null) {
            System.out.print(result2.val + " ");
            result2 = result2.next;
        }
        System.out.println();

        // test cases 3
        ListNode head3 = new ListNode(1, new ListNode(2));
        int n3_val = 1;
        ListNode result3 = solution.removeNthFromEnd(head3, n3_val);
        while (result3 != null) {
            System.out.print(result3.val + " ");
            result3 = result3.next;
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