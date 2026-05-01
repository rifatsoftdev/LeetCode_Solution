
// Singly-Linked List Node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Doubly-Linked List Node definition
struct DoublyListNode {
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode() : val(0), prev(nullptr), next(nullptr) {}
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    DoublyListNode(int x, DoublyListNode *prev, DoublyListNode *next) : val(x), prev(prev), next(next) {}
};