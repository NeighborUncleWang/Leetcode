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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //or we can use decltype to get the type of lambda
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>>
        heap([](ListNode* lhs, ListNode* rhs) -> bool {
            return rhs->val < lhs->val;
        });
        // 用lambda initiliaze 的写法，其实这种写法更简单方便，以后还是用这种写法比较好
        // auto comp = [](ListNode* lhs, ListNode* rhs) {
        //     return lhs->val > rhs->val;
        // };
        // priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> heap(comp);
        ListNode temp(-1);
        ListNode* dummy = &temp;
        ListNode* iterator = dummy;
        for (ListNode* list : lists) {
            if (list != nullptr) {
                heap.push(list);
            }
        }
        //其实while loop里可以不用current变量
        //全程用heap.top()代替
        //那样可以节省一行代码量
        while (!heap.empty()) {
            ListNode* current = heap.top();
            iterator->next = current;
            iterator = iterator->next;
            heap.pop();
            if (current->next != nullptr) {
                heap.push(current->next);
            }
        }
        return dummy->next;
    }
};
