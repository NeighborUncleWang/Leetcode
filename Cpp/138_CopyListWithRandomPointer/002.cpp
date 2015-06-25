/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return head;
        }
        auto oldList = head;
        RandomListNode* newList;
        while (oldList != nullptr) {
            auto node = new RandomListNode(oldList->label);
            node->next = oldList->next;
            oldList->next = node;
            oldList = node->next;
        }
        oldList = head;
        while (oldList != nullptr) {
            if (oldList->random != nullptr) {//remember to rest whether oldList->random != nullptr
                oldList->next->random = oldList->random->next;
            }
            oldList = oldList->next->next;
        }
        oldList = head;
        auto result = head->next;
        while (oldList != nullptr) {
            newList = oldList->next;
            oldList->next = newList->next;
            if (newList->next != nullptr) {//remember to test whether euqals to nullptr
                newList->next = newList->next->next;
            }
            oldList = oldList->next;
        }
        return result;
    }
};
