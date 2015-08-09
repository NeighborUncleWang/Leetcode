001.cpp:
Time complexity: O(n)
Space complexity: O(n)
002.cpp:
Time complexity: O(n)
Space complexity: O(n)
I think 002.cpp has an issue. When test case is "ab", "aa" and i == 1, mapStoT[s[i]] will be undefined since 'b' is not in mapStoT at that time(cout << char{} outputs nothing).
