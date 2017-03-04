001.cpp:
Time complexity: O(1)
Space complexity: O(1)
Stephan说这种iterator的题最好不要存输入的数据结构的拷贝，比如这题拷贝一个vec2d然后用index来access，这样不好。最好是存vec2d的iterator。这样当你iterator过程中vec2d的值变了可以体现出来。
Reference:
https://leetcode.com/discuss/50292/7-9-lines-added-java-and-c-o-1-space
001.cpp:
Time complexity: O(1)
Space complexity: O(n)
This is my solution, derived from Q281.Zigzag Iterator.