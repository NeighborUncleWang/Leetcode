001.cpp:
Time complexity: O(n)
Space complexity: O(1)
My solution.
用092_ReverseLinkedListII的方法来reverse每个group里的nodes。
思路是找到要reverse的range里的第一个node标为start，start的前置节点标为predecessor，然后每次把start后一个节点then插入到predecessor和predecessor->next之间。整个过程predecessor指向的节点不变，predecessor指向节点的位置也不变。start指向的节点不变，start指向的节点的位置不断地后移(因为start->next不断被插入到predecessor和predecessor->next之间)
002.cpp:
Time complexity: O(n)
Space complexity: O(1)
自己又写了一个每次把node插入到整个group最后一个元素和下一个元素之间的方法。插入的位置和001.cpp刚好反过来。
003.cpp:
Time complexity: O(n)
Space complexity: O(1)
这个方法不好，太复杂了，不用看了其实。
use a predecessor to record the previous node.
http://blog.csdn.net/linhuanmars/article/details/19957455