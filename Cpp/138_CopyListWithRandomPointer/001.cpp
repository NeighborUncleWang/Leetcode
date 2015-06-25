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
        auto sentinel = new RandomListNode(0);
        unordered_map<RandomListNode*, RandomListNode*> hashMap;
        auto newList = sentinel;
        auto oldList = head;
        while (oldList != nullptr) {
            auto node = new RandomListNode(oldList->label);
            newList->next = node;
            newList = node;
            hashMap[oldList] = node;
            oldList = oldList->next;
        }
        oldList = head;
        newList = sentinel->next;
        while (oldList != nullptr) {
            newList->random = hashMap[oldList->random];
            newList = newList->next;
            oldList = oldList->next;
        }
        auto result = sentinel->next;
        delete sentinel;
        return result;
    }
};
