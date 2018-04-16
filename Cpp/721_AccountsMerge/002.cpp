class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> map;
        unordered_map<string, string> roots;
        unordered_map<string, int> weights;
        for (auto& account : accounts) {
            string name = account.front();
            for (int i = 1; i < account.size(); ++i) {
                map[account[i]] = name;
                roots[account[i]] = account[i];
                weights[account[i]] = 1;
            }
        }
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                unite(account[i], account[1], roots, weights);
            }
        }
        unordered_map<string, vector<string>> unions;
        for (auto& it : map) {
            unions[find(it.first, roots)].push_back(it.first);
        }
        vector<vector<string>> res;
        for (auto& it : unions) {
            vector<string> temp;
            temp.push_back(map[it.first]);
            temp.insert(temp.end(), it.second.begin(), it.second.end());
            sort(temp.begin() + 1, temp.end());
            res.push_back(move(temp));
        }
        return res;
    }
private:
    string find(string cur, unordered_map<string, string>& roots) {
        while (cur != roots[cur]) {
            roots[cur] = roots[roots[cur]];
            cur = roots[cur];
        }
        return cur;
    }
    void unite(string& lhs, string& rhs, unordered_map<string, string>& roots, unordered_map<string, int>& weights) {
        string lroot = find(lhs, roots);
        string rroot = find(rhs, roots);
        if (lroot == rroot) {
            return;
        }
        if (weights[lroot] <= weights[rroot]) {
            roots[lroot] = rroot;
            weights[rroot] += weights[lroot];
        } else {
            roots[rroot] = lroot;
            weights[lroot] += weights[rroot];
        }
    }
};
