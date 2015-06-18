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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashSet;
        ListNode* temp = head;
        while (nullptr != temp) {
            if (hashSet.end() != hashSet.find(temp)) {
                return temp;
            } else {
                hashSet.insert(temp);
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
