001.cpp:
Time complexity: O(|E|)
Space commplexity: O(|E|)
这个方法应该就是Hierholzer's Algorithm,先visit一遍，找到main path，然后再把剩下edges组成的cycle加到main path里。
Reference:
https://leetcode.com/discuss/84659/short-ruby-python-java-c
https://en.wikipedia.org/wiki/Eulerian_path