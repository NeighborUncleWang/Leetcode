001.cpp:
Time complexity: O(m * n)
Space complexity: O(m * n)
Idea:重点在于不要每次从一个gate新建一个queue开始新的bfs，那样Time complexity是O(k*m*n),k是gates数
而要同时从所有gates开始BFS。
Reference:
https://leetcode.com/discuss/60418/c-bfs-clean-solution-with-simple-explanations
002.cpp:
Time complexity: O(m * n)
Space complexity: O(m * n)
My solution.