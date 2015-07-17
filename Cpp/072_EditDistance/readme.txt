001.cpp:
Time complexity: O(m * n)
Space complexity: O(min(m, n))
002.cpp:
Time complexiyt: O(m * n)
Space complexity: O(m * n)
002.cpp is the basic DP version uses a two-diminsion matrix to store the result. 001.cpp is the improved version uses O(min(m, n)) extra space instead of O(m * n). Here we must use two vectors(row and nextRow), since when we calculate the matrix[i][j], we need matrxi[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]. Neither we calculate from left to right nor right to left can we save this extra vector.
Actually 002.cpp is much more easy to implement.
