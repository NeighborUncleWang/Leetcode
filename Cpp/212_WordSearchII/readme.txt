001.cpp:
Time complexity: O(m * n * 4 ^ L)(L is the longest word in the dictionary)
Space complexity: O(m * n * L)(the recursive stack) + O(26^L)(the trie)
cost 136ms. Has memory leaking since the trie is not properly destroyed.
