class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> map;
        unordered_map<string, vector<string>> adj_list;
        for (auto& account : accounts) {
            string email = account.front();
            for (int i = 1; i < account.size(); ++i) {
                adj_list[account[1]].push_back(account[i]);
                adj_list[account[i]].push_back(account[1]);
                map[account[i]] = email;
            }
        }
        unordered_set<string> visited;
        queue<string> q;
        vector<vector<string>> res;
        for (auto& it : adj_list) {
            if (visited.find(it.first) == visited.end()) {
                q.push(it.first);
                visited.insert(it.first);
                vector<string> emails{map[it.first]};
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    emails.push_back(cur);
                    for (auto& neighbor : adj_list[cur]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
                sort(emails.begin() + 1, emails.end());
                res.push_back(move(emails));
            }
        }
        return res;
    }
};
