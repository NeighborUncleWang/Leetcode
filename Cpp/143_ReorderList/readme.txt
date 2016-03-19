001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/35599/java-solution-with-3-steps
这里reverse后半部分的时候用的是092_ReverseLinkedListII的方法，这样reverse完整个list还是完整的，所以要把slow->next设为nullptr。
或者也可以按reference里那样去掉slow->next = nullptr的操作，直接把后面半部分一个个插入到前半部分。
