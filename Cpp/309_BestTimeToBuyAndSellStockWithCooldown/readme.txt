001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/71354/share-my-thinking-process
其实可以直接得出buy[i] = max(sell[i - 2] - price, buy[i - 1]);
因为sell[i - 2]表示sell动作只能发生在第i-2或者第i-2天之前，所以这个保证了中间空出一天rest。
002.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/72030/share-my-dp-solution-by-state-machine-thinking
其实这个做法和上面原理是一样的。S0保证了sell和buy之间有一天休息。