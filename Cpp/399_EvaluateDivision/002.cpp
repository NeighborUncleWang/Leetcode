class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> adj_list;
        for (int i = 0; i < equations.size(); ++i) {
            //下面两行其实可以不用，因为有a/b = 2 也一定会有b/a = 0.5
            //最后会根据a/b*b/a 得到a/a = 1
            //adj_list[equations[i].first][equations[i].first] = 1;
            //adj_list[equations[i].second][equations[i].second] = 1;
            adj_list[equations[i].first][equations[i].second] = values[i];
            adj_list[equations[i].second][equations[i].first] = 1 / values[i];
        }
        for (auto k : adj_list) {
            for (auto i : adj_list[k.first]) {
                for (auto j : adj_list[k.first]) {
                    adj_list[i.first][j.first] = adj_list[i.first][k.first] * adj_list[k.first][j.first];
                }
            }
        }
        vector<double> result;
        for (auto query : queries) {
            if (adj_list.count(query.first) && adj_list[query.first].count(query.second)) {
                result.push_back(adj_list[query.first][query.second]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};