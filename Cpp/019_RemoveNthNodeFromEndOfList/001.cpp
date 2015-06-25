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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {//actually in this problem I don't need to check this cases, since it mentions that the n will always be valid. In an interview, I'd better be careful.
			return nullptr;
		}
		ListNode* helper = new ListNode(0);
        helper->next = head;
        ListNode* runner = helper;
        for (int i = 0; i < n; ++i) {
            runner = runner->next;
        }
        ListNode* walker = helper;
        while (runner->next != nullptr) {
            runner = runner->next;
            walker = walker->next;
        }
        ListNode* next = walker->next;
        walker->next = walker->next->next;
        delete next;
        auto result = helper->next;
        delete helper;
        return result;
    }
};
