001.cpp:
Time complexity: O(m * n)
Space complexity: O(min(m, n))
002.cpp:
Time complexiyt: O(m * n)
Space complexity: O(m * n)
002.cpp is the basic DP version uses a two-diminsion matrix to store the result. 001.cpp is the improved version uses O(min(m, n)) extra space instead of O(m * n). Here we must use two vectors(row and nextRow), since when we calculate the matrix[i][j], we need matrxi[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]. Neither we calculate from left to right nor right to left can we save this extra vector.
Actually 002.cpp is much more easy to implement.

Reference:
https://leetcode.com/discuss/43398/20ms-detailed-explained-c-solutions-o-n-space

这题code ganker的讲解有问题，我认为他插入删除word1的对应关系讲反了。
1.Replace word1[i - 1] by word2[j - 1], 相当于wod1[0...i - 2]经过dp[i - 1][j - 1]次的edit之后变成word2[0...j - 2],然后再把word1[i - 1]换成word2[j - 1],这样word1[0...i - 1]就变成了word2[0...j -1 ]，所以有(dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
2.Delete word1[i - 1]，相当于word1[0..i - 2]经过dp[i - 1][j]次edit变成word2[0..j - 1],然后再删除word1[i - 1],这样word1[0...i - 1]就变成了word2[0...j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
3.Insert word2[j - 1] to word1[0..i - 1]. 相当于word1[0...i - 1]经过dp[i][j - 1]次edit变成word2[0...j - 2]，然后再insert word2[j - 1] to tranformed word1[0...i - 1], 这样word1[0...i - 1]就变成了word2[0...j - 1](dp[i][j] = dp[i][j - 1] + 1 (for insertion)).