001.cpp:
Time complexity: O(n^3)
Space complexity: O(1)
Reference:
https://www.hrwhisper.me/leetcode-guess-number-higher-lower-ii/
https://discuss.leetcode.com/topic/51356/two-python-solutions

Copied from first reference:
题意：给定一个数字n，从1~n中选取一个数字y让你猜。在猜的过程中，会告诉你你当前猜的数字x是比y大还是小，猜错的话，需要付$x。给定n,我们最少需要多少的钱来确保我们猜出y呢？

思路：在 374 Guess Number Higher or Lower 中，我们采用二分法来进行查找，但这题并不是用二分法。

这题要求我们在猜测数字y未知的情况下（1~n任意一个数），要我们在最坏情况下我们支付最少的钱。也就是说要考虑所有y的情况。

我们假定选择了一个错误的数x，（1<=x<=n && x!=y ）那么就知道接下来应该从[1,x-1 ] 或者[x+1,n]中进行查找。 假如我们已经解决了[1,x-1] 和 [x+1,n]计算问题，我们将其表示为solve(L,x-1) 和solve(x+1,n)，那么我们应该选择max(solve(L,x-1),solve(x+1,n)) 这样就是求最坏情况下的损失。总的损失就是 f(x) = x + max(solve(L,x-1),solve(x+1,n))

那么将x从1~n进行遍历，取使得 f(x) 达到最小，来确定最坏情况下最小的损失，也就是我们初始应该选择哪个数。