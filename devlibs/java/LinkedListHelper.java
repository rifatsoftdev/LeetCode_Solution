package devlibs.java;



public class LinkedListHelper {
    public static ListNode buildList(int... values) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;

        for (int v : values) {
            cur.next = new ListNode(v);
            cur = cur.next;
        }

        return dummy.next;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }
}
