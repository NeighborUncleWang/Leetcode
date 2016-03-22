001.cpp:
Time complexity:
push: O(n)
pop: O(1)
top: O(1)
emtpy: O(1)
Reference:
https://leetcode.com/discuss/46975/a-simple-c-solution
This version is for situations that push < top + pop
002.cpp:
Time complexity: 
push: O(1)
pop: O(n)
top: O(n)
empty: O(1)
Reference:
This version is for situations that push > top + pop
不过StefanPochmann留言评价这种方法"Unnecessarily complicated"。其实 push > top + pop的情况确实很少发生，大部分情况都是 push < top + pop