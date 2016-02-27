/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        auto tail = head;
        int size = 1;
        while (tail->next) {
            ++size;
            tail = tail->next;
        }
        tail->next = head;
        if (k % size) {
            for (int i = 0; i < size - k % size; ++i) {
                tail = tail->next;
            }
        }
        auto newHead = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};