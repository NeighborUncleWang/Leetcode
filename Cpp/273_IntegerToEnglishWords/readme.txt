001.cpp:
Time complexity: O(n)
Space complexity: O(1)
也可以每次都把新的string连接到当前string后面，不过这样处理起来比较麻烦，要先算出一个base，然后每次int digits = num / base % 1000, num每次不用变化，只变化base。
Reference:
Combine the first reference with the solution of jianchao.li.fighter in second reference
https://leetcode.com/discuss/55462/my-clean-java-solution-very-easy-to-understand
https://leetcode.com/discuss/55273/my-java-solution?show=55387#a55387
002.cpp:
Time complexity: O(n)
Space complexity: O(1)
每次把新的string连接到当前string后面的做法，速度上和001.cpp好像也没差别。