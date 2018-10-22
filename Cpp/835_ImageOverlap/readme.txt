001.cpp:
Time complexity: O(n^2)
Space complexity: O(n^2)
Reference:
https://leetcode.com/problems/image-overlap/discuss/130623/C%2B%2BJavaPython-Straight-Forward
之所以i / n * 100 + i % n是为了防止1被移出界之后依然被算成重叠，这样就不用判断是否越界的问题
否则假设n=2,如果直接push (i), 会导致的问题是(0, 2)这种越界的位置和（1，0）这种合法的位置是一样的index
