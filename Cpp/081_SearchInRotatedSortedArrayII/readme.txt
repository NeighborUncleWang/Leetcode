Time complexity : O(n)
Space complexity : O(1)
A simply modification from SearchInRotatedSortedArray. When nums[median] == nums[low], we just ++low to skip the duplicates. 
