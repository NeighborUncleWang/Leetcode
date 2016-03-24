001.cpp:
Time complexity: O(n*k^2)
Space complexity: O(n*k)(n is the size of words, k is the length of longest word)
Reference:
https://leetcode.com/discuss/91531/accepted-short-java-solution-using-hashmap
对于每一个word，我们要遍历他的所有prefix和suffix，然后分别reverse再在hashmap里search