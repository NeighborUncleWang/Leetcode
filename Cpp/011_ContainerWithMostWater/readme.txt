Time complexity: O(n)
Space complexity: O(1)
Start from the biggest and smallest indices. If height[left] < height[right], then height[left] is the bottleneck, then ++low, and vice versa. Keep tracking the area of each container and find the biggest container.
