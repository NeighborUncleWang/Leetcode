001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Use the (size_t)char as hash funciton and uses a vector as hash map.
Reference:
https://leetcode.com/discuss/21929/share-my-c-solution
002.cpp:
Time complexity: O(n)
Space complexity: O(1)
Use unordered_map as a hash map. hashMap.size() will not exceed 256 since sizeof(char) = 1
这种题目一般都是在for loop一开始先把新元素加到集合中，然后再进行一系列操作使得集合中元素满足题目要求，比如这题的at most k distinct characters, 然后在for loop 最后update max length。