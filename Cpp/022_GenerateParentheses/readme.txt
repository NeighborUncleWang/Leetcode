001.cpp:
Time complexity: O(Cn, the Cn is the nth catalan number)
Space complexity: O(n)(the recursive stack and the sequence, is this a tail recursion?)
This version uses string& to pass the variable sequence(pass by reference), so it needs string::pop_back() to restore the field.
Reference:
https://leetcode.com/discuss/25063/easy-to-understand-java-backtracking-solution
002.cpp:
Time complexity: O(Cn, the Cn is the nth catalan number)
Space complexity: O(n)(the recursive stack and the sequence, is this a tail recursion?)
My solution.
