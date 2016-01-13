001.cpp:
Time complexity: O(n)
Space complexity: O(n)
Reference:
https://leetcode.com/discuss/24478/i-did-it-in-10-lines-of-c
002.cpp:
Time complexity: O(n)
Space complexity: O(n)
这里没有check s.size() < 9的情况，第一个loop s[i]其实已经越界了，但是结果是对的，总感觉不太好。
003.cpp:
Time complexity: O(n)
Space complexity: O(n)
用rolling hash的方法算hashCode,其实001.cpp和002.cpp本质上也是rolling hash。
Reference:
https://leetcode.com/discuss/24595/short-java-rolling-hash-solution