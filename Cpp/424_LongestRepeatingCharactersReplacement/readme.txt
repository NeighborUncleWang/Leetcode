001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://discuss.leetcode.com/topic/63494/java-12-lines-o-n-sliding-window-solution-with-explanation
note:
result = max(result, right - left + 1 - max_count);这里[left, right]之间的substring也可能不是valid的，但是因为invalid的substring不可能比之前得到的valid的substring长，所以没有关系。
具体解释可以看这篇:
https://discuss.leetcode.com/topic/63494/java-12-lines-o-n-sliding-window-solution-with-explanation/3