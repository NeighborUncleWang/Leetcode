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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        for (auto iter1 = l1; iter1 != nullptr; iter1 = iter1->next) {
            s1.push(iter1->val);
        }
        for (auto iter2 = l2; iter2 != nullptr; iter2 = iter2->next) {
            s2.push(iter2->val);
        }
        ListNode* head = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            auto node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        return head;
    }
};