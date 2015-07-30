001.cpp:
Time complexity: O(max(s1, s2))
Space complexity: O(1)
002.cpp:
Time complexity: O(max(s1, s2))
Space complexity: O(1)
003.cpp:
Time complexity: O(max(s1, s2))
Space compelxtiy: O(s1 + s2)
前置的0对version没有影响，030.1 == 30.1 但是后置的0有影响 30.30.300 > 30.30.30
以'.' 为delimiter，将string分成substring，然后用stoi函数转成int比较大小。如果超出某一个字符串的长度就让stoi返回0.
http://wlcoding.blogspot.com/2015/03/compare-version-numbers.html?view=sidebar
