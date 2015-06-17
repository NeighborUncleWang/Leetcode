001.cpp:
Time complexity: O(nlogn)
Space complexity: O(1)
Use divide-and-conquer to solve the problem. Cost 24ms.
002.cpp:
Time compleixty: O(n)
Space complexity: O(n)
Use hash map to store the element in the nums vector. The key is nums[i], the value is the appear times of nums[i]. Costs 33ms.
003.cpp
Time complexity: O(n)
Space complexity: O(1)
Bit manipulation, if nums[i] appears more than n / 2 times, then every bit of nums[i] should appear more than n / 2 times. Int is 4 bytes in both 32-bit machine and 64-bit machine. Costs 52ms(slowest).
004.cpp
Time complexity: O(nlogn)
Space complexity: O(1)
Simply sort the array and access the nums[n / 2]. Costs 41ms.
