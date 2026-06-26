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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* second = slow -> next;
        ListNode* prev = slow -> next = nullptr;

        //now we reverse the second half 
        while (second != nullptr) {
            ListNode* tmp = second -> next;
            second -> next = prev;
            prev = second;
            second = tmp;
        }

        //now we merge the two halves
        ListNode* first = head;
        second = prev;

        while (second != nullptr) {
            ListNode* tmp1 = first -> next;//save next of first half i.e 2
            ListNode* tmp2 = second -> next;//save next of second half i.e 
            first -> next = second; //1 -> 5
            second -> next = tmp1; //5 -> 2
            first = tmp1;
            second = tmp2;
        }
    }
};
