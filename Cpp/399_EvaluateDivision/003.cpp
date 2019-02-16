class Solution {
private:
    string getRoot(unordered_map<string, string>& roots, string node) {
        while (node != roots[node]) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }
    void unionNodes(string s1, string s2, unordered_map<string, double>& value,
                    unordered_map<string, string>& roots, unordered_map<string, int>& weights, double num) {
            string root1 = getRoot(roots, s1), root2 = getRoot(roots, s2);
            bool root1Smaller = weights[root1] < weights[root2];
            if (root1 != root2) {
                double ratio = num * value[s2] / value[s1];
                for (auto& it : roots) {
                    if (getRoot(roots, it.first) == root1) {
                        value[it.first] *= ratio;
                    }
                }
                if (root1Smaller) {
                    roots[root1] = root2;
                    weights[root2] += weights[root1];
                } else {
                    roots[root2] = root1;
                    weights[root1] += weights[root2];
                }
            }
        }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, double> value;
        unordered_map<string, string> roots;
        unordered_map<string, int> weights;
        for (int i = 0; i < equations.size(); ++i) {
            string s1 = equations[i].first;
            string s2 = equations[i].second;
            if (roots.find(s1) == roots.end() && roots.find(s2) == roots.end()) {
                value[s1] = values[i];
                value[s2] = 1;
                roots[s2] = s2;
                roots[s1] = s2;
                weights[s1] = 1;
                weights[s2] = 1;
            } else if (roots.find(s1) == roots.end()) {
                roots[s1] = s2;
                value[s1] = value[s2] * values[i];
                weights[s1] = 1;
                weights[s2] += 1;
            } else if (roots.find(s2) == roots.end()) {
                roots[s2] = s1;
                value[s2] = value[s1] * 1.0 / values[i];
                weights[s2] = 1;
                weights[s1] += 1;
            } else {
                unionNodes(s1, s2, value, roots, weights, values[i]);
            }
        }
        vector<double> res;
        for (auto& query : queries) {
            if (roots.find(query.first) == roots.end() ||
            roots.find(query.second) == roots.end() ||
            getRoot(roots, query.first) != getRoot(roots, query.second)) {
                res.push_back(-1);
            } else {
                res.push_back(value[query.first] / value[query.second]);
            }
        }
        return res;
    }
};
