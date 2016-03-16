class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int p = A[0].size();
        int n = B[0].size();
        vector<vector<int>> C(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < p; ++k) {
                //先遍历matrix A中每一个元素
                //然后对每一个非0元素一次性把相关的乘法全部做完
                //所以主要是if (A[i][k])这步判断能节省O(n)的时间
                //if (B[k][j])这步只能节省O(1)时间
                //感觉有点可有可无的样子
                //去掉B[k][j]时间从28ms减慢到30ms
                //变化不是很大
                if (A[i][k] != 0) {
                    for (int j = 0; j < n; ++j) {
                        if (B[k][j] != 0) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
        return C;
    }
};