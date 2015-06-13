Time Complexity: O(n)
Space Complexity: O(1)
The solution is similiar to MaximumSubarray. Instead of just record the local max product, we also need to record local minimum product. Since the most negative number multiplied by a negative number will also produce a big value.
