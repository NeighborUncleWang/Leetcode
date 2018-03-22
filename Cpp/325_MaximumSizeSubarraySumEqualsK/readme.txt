001.cpp:
Time complexity: O(n)
Space complexity: O(n)
We can also initialize hashMap[0] = -1 to make the code more concise. But I think current version is more readable.
加这个dummy node到hashMap里是为了handle subarray从0开始的corner case.
Reference:
https://leetcode.com/discuss/77873/o-n-c-solution-using-unordered_map
https://leetcode.com/discuss/78533/java-o-n-explain-how-i-come-up-with-this-idea
002.cpp:
The dummy node version.
