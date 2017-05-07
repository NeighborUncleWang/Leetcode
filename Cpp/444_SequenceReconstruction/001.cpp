class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) return false;
        int n = org.size();
        vector<int> indices(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            indices[org[i]] = i;
        }
        vector<bool> pair(n, false);
        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] < 0 || seq[i] > n) {
                    return false;
                }
                if (i > 0 && indices[seq[i - 1]] >= indices[seq[i]]) {
                    return false;
                }
                if (i > 0 && indices[seq[i - 1]] + 1 == indices[seq[i]]) {
                    pair[indices[seq[i - 1]]] = true;
                }
                //要注意一下最后元素是否出现
                //没有下面这个判断语句会导致[1],[[],[]] case出错
                if (indices[seq[i]] == n - 1) {
                    pair[n - 1] = true;
                }
            }
        }
        //这里要检查pair每个元素是否为true
        return count(pair.begin(), pair.end(), true) == n;
    }
};