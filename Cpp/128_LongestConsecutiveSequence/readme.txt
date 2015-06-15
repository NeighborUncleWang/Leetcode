Time complexity: O(n)
Space complexity: O(n)
use a hashset to store the value in the nums vector. Then for each element temp in the nums vector, search it in the hashset. Then search temp - 1, temp - 2... tempp + 1, temp + 2... Each time we found one element, delete it from the hashset, this can guarantee the time complexity to be O(n)(prevent duplicate search).
