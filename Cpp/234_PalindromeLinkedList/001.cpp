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
        if (head == nullptr) {
            return true;
        }
        bool result = true;
        ListNode* walker = head;
        ListNode* runner = head;
        while (runner->next != nullptr && runner->next->next != nullptr) {
            runner = runner->next->next;
            walker = walker->next;
        }
        auto secondHead = walker->next;
        secondHead = reverseList(secondHead);
        auto secondPartIterator = secondHead;
        while (secondPartIterator != nullptr) {
            if (head->val != secondPartIterator->val) {
                result = false;//we can't return false here, otherwise the linkedlist will remain modified, we need to restore the linkedlist
                break;
            }
            secondPartIterator = secondPartIterator->next;
            head = head->next;
        }
        reverseList(secondHead);
        return result;
    }
private:
    ListNode* reverseList(ListNode* head) {
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
