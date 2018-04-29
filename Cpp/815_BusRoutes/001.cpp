class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                map[stop].push_back(i);
            }
        }
        unordered_set<int> visited;
        queue<int> q;
        q.push(S);
        int res = 0;
        while (!q.empty()) {
            ++res;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                for (int bus : map[cur]) {
                    if (visited.find(bus) == visited.end()) {
                        for (int stop : routes[bus]) {
                            if (stop == T) {
                                return res;
                            } else {
                                q.push(stop);
                            }
                        }
                        visited.insert(bus);
                    }
                }
            }
        }
        return -1;
    }
};
