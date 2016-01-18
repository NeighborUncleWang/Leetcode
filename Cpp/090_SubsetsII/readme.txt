001.cpp:
Time complexity: O(2^n)
Space complexity: O(2^n)(why not n*2^n)?
Reference:
https://leetcode.com/discuss/11905/simple-iterative-solution
其实重复的subset产生的原因就是把之前result里前面的部分又取出来把nums[i]重新加了一遍，所以一旦出现重复，就要避免把这些subset拿出来加。
002.cpp:
Time complexity: O(2^n)
Space complexity: O(2^n)
Reference:
https://leetcode.com/discuss/14902/c-solution-and-explanation
思想是一样的，当有元素重复时，要么全部不加入subset，要么加入1个，2个...全部。
