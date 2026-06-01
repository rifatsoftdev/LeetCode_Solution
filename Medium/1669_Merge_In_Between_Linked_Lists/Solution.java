

public class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        int i = 0;
        ListNode prev = null;
        ListNode curr = list1;

        while (curr != null && i < a) {
            prev = curr;
            curr = curr.next;
            i++;
        }

        ListNode tail = list2;

        while (tail.next != null) {
            tail = tail.next;
        }

        if (prev != null) {
            prev.next = list2;
        } else {
            list1 = list2;
        }

        tail.next = curr;

        for (i = a; i <= b && curr != null; i++) {
            curr = curr.next;
        }

        tail.next = curr;

        return list1;
    }

    private static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val);
            if (current.next != null) {
                System.out.print(" -> ");
            }
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // test cases 1
        ListNode list1 = new ListNode(10, new ListNode(1, new ListNode(13, new ListNode(6, new ListNode(9, new ListNode(5))))));
        ListNode list2 = new ListNode(1000000, new ListNode(1000001, new ListNode(1000002)));
        ListNode result = solution.mergeInBetween(list1, 3, 4, list2);
        printList(result); // Expected output: 10 -> 1 -> 13 -> 1000000 -> 1000001 -> 1000002 -> 5
    
        // test cases 2
        ListNode list3 = new ListNode(0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
        ListNode list4 = new ListNode(1000000, new ListNode(1000001, new ListNode(1000002, new ListNode(1000003, new ListNode(1000004)))));
        ListNode result2 = solution.mergeInBetween(list3, 2, 5, list4);
        printList(result2); // Expected output: 0 -> 1 -> 1000000 -> 1000001 -> 1000002 -> 1000003 -> 1000004 -> 6
        
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