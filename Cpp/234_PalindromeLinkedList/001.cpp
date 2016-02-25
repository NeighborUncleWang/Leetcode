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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        auto fast = head;
        auto slow = head;
        //如果fast和slow都是从head开始的话
        //用fast->next && fast->next->next
        //如果fast和slow都是从dummy node开始的话
        //用fast && fast->next
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto secondPart = reverse(slow->next);
        auto iter2 = secondPart;
        auto iter1 = head;
        bool result = true;
        while (iter2 != nullptr) {
            if (iter2->val != iter1->val) {
                //we can't return false here, otherwise the linkedlist will remain modified, 
                //we need to restore the linkedlist
                result = false;
                break;
            }
            iter2 = iter2->next;
            iter1 = iter1->next;
        }
        reverse(secondPart);
        //after the reverse(secondPart)
        //I've checked the linkedlist
        //it's the same as before
        //so the input is can be restored
        return result;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* predecessor = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            auto next = current->next;
            current->next = predecessor;
            predecessor = current;
            current = next;
        }
        return predecessor;
    }
};