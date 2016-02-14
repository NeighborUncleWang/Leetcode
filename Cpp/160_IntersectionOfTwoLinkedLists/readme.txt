001.cpp 
idea: say A length = a + c, B length = b + c, after switching pointer, pointer A will move another b + c steps, pointer B will move a + c more steps, since a + c + b + c = b + c + a + c, it does not matter what value c is. Pointer A and B must meet after a + c + b (b + c + a) steps. If c == 0, they meet at NULL.
Time complexity: O(m + n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/66203/java-solution-without-knowing-the-difference-in-len

002.cpp, find the longer linkedlist, move the pointer by abs(lenA - lenB) steps;
