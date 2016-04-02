Time complexity: O(n)
Space complexity: O(n)
Reference:
https://leetcode.com/discuss/12780/my-concise-c-solution-ac-90-ms
一篇比较好的讲解文章。每一次计算area都是计算当前bar能在整个图里围成的最大矩形面积(除了下面提到两个bar高度相同的corner case之外的general case):
http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
给的例子中如果两个5中间的高度为4的bar高度大于5的话，右边的5计算area时会得到10，然后左边的5计算area时会得到正确答案15.这是当有相同height中间bar高度又比这个height要高的时候要注意的情况，具体例子看视频08:37:
https://youtu.be/ZmnqCZp9bBs?t=517
