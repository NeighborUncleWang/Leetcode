001.cpp:
Time complexity: O(n^2)
Space complexity: O(n)
Reference:
可以看看链接里下面的1 Answer，里面有人贴出怎么手工implement能找到插入位置的bianry search
https://leetcode.com/discuss/67533/c-typical-dp-2-solution-and-nlogn-solution-from-geekforgeek
002.cpp:
Time complexity: O(nlogn)
Space complexity: O(n)
Reference:
https://leetcode.com/discuss/67609/short-java-solution-using-dp-o-n-log-n
https://leetcode.com/discuss/67554/9-lines-c-code-with-o-nlogn-complexity
以上两个链接的解法都是一样的，包括001.cpp里的nlogn解法，都是geekforgeeks上的算法的实现。其实每次都是给新value找
一个对应的插入位置，如果这个位置在最后，那就说明可以++length，否则就把原位置的值替换掉。

upper_bound和lower_bound的记忆方法：
这个function之所以叫lower_bound是因为假设container是ascending order排列的，如果要找container中在
一个区间[a, b]里的值，就要用到lower_bound(begin(),end(), a), upper_bound(begin(), end(), b)
注意lower_bound是找第一个>=，upper_bound是找第一个>，所以upper_bound返回值减1就是<=的值.
这个和Q327_Count of Range Sum里找某个范围的值的做法是一样的，都是先找到第一个>的值，然后减1就是<=的值