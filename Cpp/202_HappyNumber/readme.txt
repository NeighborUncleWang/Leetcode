001.cpp:
Time complexity: O(n)(n is how many times the loop is excuted)
Space complexity: O(n)
Use the Floyd cycle detection algorithm.
这题一定会有环，如果最后结果是happy number，那么一定是一个length为1的环，所以slow或者fast一定都等于1.
Reference:
https://leetcode.com/discuss/33055/my-solution-in-c-o-1-space-and-no-magic-math-property-involved
https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
002.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/59684/beat-easy-understand-java-solution-with-brief-explanation