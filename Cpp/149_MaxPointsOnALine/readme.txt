001.cpp:
Time complexity: O(n^2)
Space complexity: O(n)
Reference:
https://leetcode.com/discuss/18590/sharing-my-simple-solution-with-explanation
我感觉discussion里其他高票答案不对，有个答案用map<pair<int, int>, int>来存线，但是每次insert的complexity是O(logn)
reeclapple的方法应该将map<map<int, int>, int>做容器，而不是map<int, map<int, int>>，前者会更好理解(一对a和b决定斜率作为key)。
一旦用了map复杂度就上升，不用map的话pair<int,int>又得自己想hash function，评论里有一个方法，得到int a = xdiff/gcd和int b = ydiff/gcd之后,
用long long key = a << 32 | b来得到key，这个方法还不错的样子。
