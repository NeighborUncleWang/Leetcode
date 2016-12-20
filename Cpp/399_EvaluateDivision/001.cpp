class Solution {
private:
    double dfs(unordered_map<string, unordered_map<string, double>>& adj_list, string current, string target, 
    unordered_set<string>& visited) {
        //下面这句判断其实只在第一次递归dfs的时候有可能成立
        //因为后面都在图里面搜索，不可能再出现start不在图里的情况
        //if (adj_list.find(current) == adj_list.end()) return -1.0;
        if (current == target) return 1.0;
        visited.insert(current);
        double result = 0;
        for (auto it : adj_list[current]) {
            //这里一定要记住=的优先级比>要低，不能写成
            //if (visited.count(it.first) == 0 && (result = dfs(adj_list, it.first, target, visited) > 0))
            //那样的话会变成(result = (dfs(adj_list, it.first, target, visited) > 0))=>(result = 1)
            //这个bug不容易发现
            //或者写成两层判断语句
            //if (visited.count(it.first) == 0) {
            //  result = dfs(adj_list, it.first, target, visited);
            //  if (result > 0) do ....
            //}
            if (visited.count(it.first) == 0 && (result = dfs(adj_list, it.first, target, visited)) > 0) {
                visited.erase(current);
                return adj_list[current][it.first] * result;
            }
        }
        visited.erase(current);
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> adj_list;
        for (int i = 0; i < equations.size(); ++i) {
            adj_list[equations[i].first][equations[i].second] = values[i];
            adj_list[equations[i].second][equations[i].first] = 1 / values[i];
        }
        vector<double> result;
        unordered_set<string> visited;
        for (auto query : queries) {
            result.push_back(adj_list.count(query.first) ? dfs(adj_list, query.first, query.second, visited) : -1);
        }
        return result;
    }
};