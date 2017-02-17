001.cpp:
Time complexity: O(?)
Space complexity: O(?)
Using trie method to store the prefixes.
Reference:
https://discuss.leetcode.com/topic/63516/explained-my-java-solution-using-trie-126ms-16-16
002.cpp:
Time complexity: O(k*k*n^k)
有k*n^k个square，每个square要花费O(k)（每行O(1），整个squareO(k）)时间去检查是否valid
Space complexity: O(?)
Using hashmap to store the prefixes, slower than the trie method.
Reference:
https://discuss.leetcode.com/topic/63428/short-python-c-solution
003.cpp:
Time complexity: O(k^2*k*n^k)(k is the size of word, n is the size of words)
因为有k*n^k个square，每个square要花费O(k^2)时间去检查是否valid
Space complexity: O(?)
Using hashmap to store the prefixes, slower than the trie method.
我的暴力解法，速度比较慢，但是现在还是能pass OJ(1445ms).