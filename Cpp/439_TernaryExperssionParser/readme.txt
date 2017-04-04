001.cpp:
Time complexity: O(n)
Space compelxity: O(n)
从后往前找到第一个'?'来判断一个三元表达式的值，找':'没有用。因为三元表达式group right-to-left（右结合），所以要从右往左找，然后因为要判断一个三元表达式必须要判断'?'之前的condition是true or false,所以要先找到'?'而不是':'
Reference:
https://discuss.leetcode.com/topic/64409/very-easy-1-pass-stack-solution-in-java-no-string-concat
Another good solution:
https://discuss.leetcode.com/topic/64389/easy-and-concise-5-lines-python-java-solution