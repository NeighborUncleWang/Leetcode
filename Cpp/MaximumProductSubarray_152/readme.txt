Time Complexity: O(n)
Space Complexity: O(1)
The solution is similiar to MaximumSubarray. Instead of just record the local max product, we also need to record local minimum product. Since the most negative number multiplied by a negative number will also produce a big value.

Official Solution
-----------------------------------
Besides keeping track of the largest product, we also need to keep track of the smallest product. Why? The smallest product, which is the largest in the negative sense could become the maximum when being multiplied by a negative number.

Let us denote that:

f(k) = Largest product subarray, from index 0 up to k. Similarly,

g(k) = Smallest product subarray, from index 0 up to k. Then,

f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] ) There we have a dynamic programming formula. Using two arrays of size n, we could deduce the final answer as f(n-1). Since we only need to access its previous elements at each step, two variables are sufficient.
