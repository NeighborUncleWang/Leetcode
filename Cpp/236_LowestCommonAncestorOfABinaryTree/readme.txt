001.cpp:
Time complexity: O(h)
Space complexity: O(h)
The recursive version.
Reference:
https://leetcode.com/discuss/45386/4-lines-c-java-python-ruby
这题如果每个treeNode有parent指针的话可以像160_IntersectionOfTwoLinkedLists一样用hashset存其中一个node向上走访问过的元素，然后看另一个node向上走的过程中是否有遇到任何node在里面