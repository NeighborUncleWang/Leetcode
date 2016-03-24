001.cpp:
Time complexity: O(25*L*sizeof(wordDict))
Space compleixyt: O(25*L*sizeof(wordDict))
Reference:
https://leetcode.com/discuss/42006/easy-76ms-c-solution-using-bfs
I use an extra hashset visited to avoid erase string from wordList.
002.cpp:
Time complexity: O(25*L*sizeof(wordDict))
Space compleixyt: O(25*L*sizeof(wordDict))
Reference:
https://leetcode.com/discuss/42006/easy-76ms-c-solution-using-bfs
002.cpp uses two-end BFS. 更难实现，但是速度比001.cpp快了很多. 88ms vs 376ms(不过002.cpp是从wordList中直接删除word，确实会快一些)