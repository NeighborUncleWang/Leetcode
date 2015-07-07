001.cpp:
Time complexity: O(n)
Space complexity: O(1)
002.cpp WILL NOT WORK! 另一种试图比较result和x最高位异或值的方法也不会work，都是因为输入-10这个testcase有问题（因为result最开始那次循环会保持0，但是x还是一个负数，所以就被判成符号位不同了）
