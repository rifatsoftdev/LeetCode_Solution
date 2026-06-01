#include "../../devlibs/cpp/cpphelper.h"

using namespace std;


// NOTE:
// For LeetCode submission, copy only the `class Solution` part.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;
        ListNode* prev = nullptr;
        ListNode* curr = list1;
        
        while (curr != nullptr && i < a) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        ListNode* tail = list2;

        while (tail->next != nullptr) {
            tail = tail->next;
        }

        if (prev != nullptr) {
            prev->next = list2;
        } else {
            list1 = list2;
        }

        tail->next = curr;

        for (i = a; i <= b && curr != nullptr; i++) {
            curr = curr->next;
        }

        tail->next = curr;

        return list1;
    }
};


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;

    // test cases 1
    ListNode* list1 = createSinglyLinkList({10,1,13,6,9,5});
    int a1 = 3, b1 = 4;
    ListNode* list2 = createSinglyLinkList({1000000,1000001,1000002});
    ListNode* ans1 = solution.mergeInBetween(list1, a1, b1, list2);
    printSinglyLinkList(ans1);

    // test cases 2
    ListNode* list3 = createSinglyLinkList({0,1,2,3,4,5,6});
    int a2 = 2, b2 = 5;
    ListNode* list4 = createSinglyLinkList({1000000,1000001,1000002,1000003,1000004});
    ListNode* ans2 = solution.mergeInBetween(list3, a2, b2, list4);
    printSinglyLinkList(ans2);

    return 0;
}