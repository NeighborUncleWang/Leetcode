Time complexity: O(n)
Space complexity: O(1)
Start from the biggest and smallest indices. If height[left] < height[right], then height[left] is the bottleneck, then ++low, and vice versa. Keep tracking the area of each container and find the biggest container.
Reference:
https://leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm