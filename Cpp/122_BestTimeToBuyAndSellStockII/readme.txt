001.cpp
Time complexity: O(n)
Space complexity: O(1)
002.cpp
Time complexity: O(n)
Space complexity: O(1)
Don't code as:
for (int i = 0; i < prices.size() - 1; ++i) {//when prices.size() == 0, prices.size - 1 will become UINT_MAX, so the loop will be excuted many times. And prices[i + 1] will not make sense when prices.size() == 0
	int difference = prices[i + 1] - prices[i];
}
