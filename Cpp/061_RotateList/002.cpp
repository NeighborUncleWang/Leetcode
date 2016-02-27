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
        int size = 1;
        auto fast = head;
        while (fast->next) {
            ++size;
            fast = fast->next;
        }
        auto slow = head;
        for (int i = 0; i < size - k % size - 1; ++i) {
            slow = slow->next;
        }
        //先把linked list 连成cycle
        //再把slow->next = nullptr
        //这样可以handle k = 0的情况
        fast->next = head;
        auto newHead = slow->next;
        slow->next = nullptr;
        return newHead;
    }
};