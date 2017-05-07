class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        unordered_map<int, unordered_set<int>> adj_list;
        vector<int> indegrees(n + 1);
        int count = 0;
        for (auto& seq : seqs) {
            for (int i : seq) {
                if (i <= 0 || i > n) return false;
                if (adj_list.count(i) == 0) {
                    adj_list[i] = unordered_set<int>();
                    ++count;
                }
            }
        }
        if (count != n) return false;
        for (auto& seq : seqs) {
            for (int i = 1; i < seq.size(); ++i) {
                if (adj_list[seq[i - 1]].insert(seq[i]).second) {
                    ++indegrees[seq[i]];
                }
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        int index = 0;
        while (q.size() == 1) {
            auto current = q.front();
            q.pop();
            if (index == org.size() || org[index++] != current) return false;
            for (int neighbor : adj_list[current]) {
                if (--indegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return index == n;
    }
};