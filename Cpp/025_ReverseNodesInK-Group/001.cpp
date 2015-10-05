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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        auto current = head;
        auto predecessor = dummy;
        int count = 0;
        while (current != nullptr) {
			//must do this first, otherwise when input is [1, 2] 2, can't pass, 
			//since when count becomes 2, current is already nullptr, 
			//that will break the while loop
			current = current->next;
            ++count;
            if (count == k) {
                predecessor = reverse(predecessor, current);
                count = 0;
            }
        }
        auto result = dummy->next;
        delete dummy;
        return result;
    }
private:
    ListNode* reverse(ListNode* predecessor, ListNode* end) {
        if (predecessor == nullptr || predecessor->next == nullptr) {
            return predecessor;
        }//actually we don't need this block, since we have already test this corner case in reverseKGroupFunction
        auto head = predecessor->next;
        auto current = predecessor->next->next;
        while (current != end) {
            auto next = current->next;
            current->next = predecessor->next;
            predecessor->next = current;
            current = next;
        }
        head->next = end;
        return head;
    }
};
