001.cpp:
Time complexity: O(n!)
permutation,  O(n!) 
T(n) = T(n - 1) + T(n - 1) + T(n - 1)...... + c = (n - 1) * T(n - 1) + c
T(n - 1) = (n - 2) * T(n - 2)
T(n - 2) = (n - 3) * T(n - 2)
.....
So T(n) = n!
Space complexity: O(n!)
https://leetcode.com/discuss/64350/short-java-%26-ruby

Here is another solution using DP, but this requires me to have the knowledge about Game Theory.
https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms
http://massivealgorithms.blogspot.com/2015/07/google-interview-flip-game-iteye.html