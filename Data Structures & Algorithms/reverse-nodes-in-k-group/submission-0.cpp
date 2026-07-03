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
private:
    ListNode* getkth(ListNode* cur, int k) {
        while (cur && k > 0) {
            cur = cur -> next;
            k--;
        }
        return cur;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* grpPrev = dummy;

        while (true) {
            ListNode* kth = getkth(grpPrev, k);
            if (!kth) {
                break;
            }

            ListNode* grpNext = kth -> next;
            ListNode* prev = kth -> next;
            ListNode* curr = grpPrev -> next;

            while (curr != grpNext) {
                ListNode* tmp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = tmp;
            }

            ListNode* tmp = grpPrev -> next;
            grpPrev -> next = kth;
            grpPrev = tmp;
        }
        return dummy -> next;
    }
};
