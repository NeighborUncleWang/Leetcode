class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.emplace_back(wage[i] / (double)quality[i], quality[i]);
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> heap;
        //DBL_MAX is not supported by Leetcode
        //double res = DBL_MAX;
        double res = numeric_limits<double>::max();
        int sumQ = 0;
        for (auto& worker : workers) {
            sumQ += worker.second;
            heap.push(worker.second);
            if (heap.size() > K) {
                sumQ -= heap.top();
                heap.pop();
            }
            if (heap.size() == K) {
                res = min(res, sumQ * worker.first);
            }
        }
        return res;
    }
};
