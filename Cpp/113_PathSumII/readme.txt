001.cpp:
Time complexity: O(n)
Space complexity: O(n)
002.cpp:
Time complexity: O(n)
Space complexity: O(n)

001.cpp Using the idea of DFS, each time a node is finished, pop it from the eligiblePath vector, so we can use the reference to pass the vector instead of passing by value. 002.cpp use pass by value, so the speed is much slower than 001.cpp(16ms VS 24ms)

