001.cpp:
Time complexity: O(nklogk), suppose there are k lists, each lists has size O(n).
Space complexity: O(k)
Idea: use a heap.
https://leetcode.com/discuss/9279/a-java-solution-based-on-priority-queue
About how to construct the heap:
http://stackoverflow.com/questions/15307532/how-can-i-use-lambda-for-container-comparison-operator
002.cpp:
Time complexity: O(nklogk)
Space complexity: O(logk), this is for the space of the recursive function call stack.
Idea: divide-and-conquer
这里有关于002.cpp复杂度的分析:
https://leetcode.com/discuss/20774/sharing-straightforward-solution-without-structure-vector