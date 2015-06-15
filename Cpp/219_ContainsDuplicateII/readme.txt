Time complexity: O(n)
Space complexity: O(n)
Use one hashmap to store the value in the nums vector. The key is nums[i], the value is i. I do not consider the situation that there are more than 2 indices int the array such that nums[i] = nums[j] = nums[k]... I think my solution won't work for that situation. However, it can still pass the leetcode online judge.
-----------------
Actually it can work for that situation. The operator [] can assign new value to the corresponding key.
