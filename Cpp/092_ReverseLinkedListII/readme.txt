001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/25580/simple-java-solution-with-clear-explanation
思路是找到要reverse的range里的第一个node标为start，start的前置节点标为predecessor，然后每次把start后一个节点then插入到predecessor和predecessor->next之间。整个过程predecessor指向的节点不变，predecessor指向节点的位置也不变。start指向的节点不变，start指向的节点的位置不断地后移(因为start->next不断被插入到predecessor和predecessor->next之间)
