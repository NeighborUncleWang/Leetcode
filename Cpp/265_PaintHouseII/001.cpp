class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        pair<int, int> min1(-1, 0);
        pair<int, int> min2(-1, 0);
        for (int i = 0; i < costs.size(); ++i) {
            auto last1 = min1;
            auto last2 = min2;
            min1 = make_pair(-1, 0);
            min2 = make_pair(-1, 0);
            for (int j = 0; j < costs[0].size(); ++j) {
                //min1 and min2保存目前为止累积最小和第二小的cost还有对应的paint的index
                //以前每次新loop我只把min1和min2.second设置为INT_MAX
                //没有把min1和min2.first设置成-1
                //那样的话如果costs第一行值全部为INT_MAX
                //就没有办法更新min1.second了(不过好像也没事)，但是这种做法有点hacker
                //还有?:操作符的优先级没有+高，所以得加括号
                int cost = costs[i][j] + (j == last1.first ? last2.second : last1.second);
                if (min1.first == -1 || cost < min1.second) {
                    min2 = min1;
                    min1 = make_pair(j, cost);
                } else if (min2.first == -1 || cost < min2.second) {
                    min2 = make_pair(j, cost);
                }
            }
        }
        return min1.second;
    }
};