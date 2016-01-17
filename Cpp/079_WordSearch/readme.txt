001.cpp:
Time complexity: O(m^2*n^2)
Space complexity: O(mn)
Reference:
https://leetcode.com/discuss/23165/accepted-very-short-java-solution-no-additional-space
这道题很容易感觉出来是图的题目，其实本质上还是做深度优先搜索。基本思路就是从某一个元素出发，往上下左右深度搜索是否有相等于word的字符串。这里注意每次从一个元素出发时要重置访问标记（也就是说虽然单次搜索字符不能重复使用，但是每次从一个新的元素出发，字符还是重新可以用的）。深度优先搜索的算法就不再重复解释了，不了解的朋友可以看看wiki - 深度优先搜索。我们知道一次搜索的复杂度是O(E+V)，E是边的数量，V是顶点数量，在这个问题中他们都是O(m*n)量级的（因为一个顶点有固定上下左右四条边）。加上我们对每个顶点都要做一次搜索，所以总的时间复杂度最坏是O(m^2*n^2)，空间上就是要用一个数组来记录访问情况，所以是O(m*n)。
002.cpp:
Time complexity: O(m^2*n^2)
Space complexity: O(mn)
My own solution, it's not so good but worth recording.