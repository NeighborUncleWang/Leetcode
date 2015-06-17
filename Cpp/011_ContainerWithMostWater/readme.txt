Time complexity: O(n)
Space complexity: O(1)
Start from the biggest and smallest indices. If height[low] < height[high], then height[low] is the bottleneck, then ++low, and vice versa. Keep tracking the area of each container and find the biggest container.
