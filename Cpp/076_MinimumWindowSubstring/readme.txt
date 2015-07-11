001.cpp:
Time complexity: O(n)(n is the length of s)
Space complexity: O(t)(t is the length of t)
In my solution, I use two hash maps, actually there is another solution only using one hash map.
http://blog.csdn.net/linhuanmars/article/details/20343903
002.cpp:
Time complexity: O(n)(n is the length of s)
Space complexity: O(t)(t is the length of t)
Actually I think this version is not right. If the string has one char repeat more than INT_MAX times, then the program will crash. The unordered_map should use value_type = string::size_type instead of int. However, in this solution, the value_type sometimes may be negative, so we must use int. This is a paradox.
