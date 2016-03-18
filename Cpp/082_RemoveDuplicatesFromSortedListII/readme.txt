001.cpp:
Time complexity: O(n)
Space complexity: O(1)
先记录current->val, 测试current->next->val == val，如果为真，则代表有重复，然后把所有值为val的node全删光
如果像java不用管memory leakage的话，可以用reference里的code:
https://leetcode.com/discuss/12724/my-accepted-java-code