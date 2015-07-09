001.cpp:
Time complexity: O(Cn, the Cn is the nth catalan number)
Space complexity: O(n)(the recursive stack and the sequence, is this a tail recursion?)
This version uses string& to pass the variable sequence(pass by reference), so it needs string::pop_back() to restore the field.
002.cpp:
Time complexity: O(Cn)
Space complexity: O(n) or O(1)(Is this a tail recursion? If yes, will the space complexity become O(1)?)
This version uses string to pass the variable sequence(pass by value), so it don't need to restore the field. This will be done by the operating system.
http://fisherlei.blogspot.com/2012/12/leetcode-generate-parentheses.html
