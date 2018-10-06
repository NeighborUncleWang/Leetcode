001.cpp:
Time complexity: O(NlogN)
Space complexity: O(N)
Recursive version.
Reference:
https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/141768/Detailed-explanation-O(NlogN)

FAQ:
Question: "However, it is possible that current worker has the highest quality, so you removed his quality in the last step, which leads to the problem that you are "using his ratio without him".
Answer: It doesn't matter. The same group will be calculated earlier with smaller ratio.
And it doesn't obey my logic here: For a given ratio of wage/quality, find minimum total wage of K workers.
