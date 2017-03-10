001.cpp:
Time complexity: O(m * n * 4 ^ L)(L is the longest word in the dictionary)
Space complexity: O(m * n * L)(the recursive stack) + O(26^L)(the trie)
cost 136ms. Has memory leaking since the trie is not properly destroyed.
002.cpp是之前的一个错误写法，这个test case过不去：
["ab"]
["a", "ab"]
因为a和ab有唯一的prefix “a”, 所以找到"a"之后就返回的话会导致找不到"ab".