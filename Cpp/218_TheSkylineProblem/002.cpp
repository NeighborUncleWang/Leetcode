class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> heights;
        vector<pair<int, int>> xPositions;
        vector<pair<int, int>> result;
        //这里必须让左边界的高度值为负值，因为对pair1.first == pair2.first时，pair1.second < pair2.second才能保证
        //pair1排在pair2前面, 这是为了当前一栋建筑的右边界和后一栋建筑的左边界相等时，保证multiset里先进行插入操作后进行删除操作
        //这样能防止出现两次（x,0）,（x,height）的结果
        //否则会出现如下错误：
        //Input:
        //[[0,2,3],[2,5,3]]
        //Output:
        //[[0,3],[2,0],[2,3],[5,0]]
        //Expected:
        //[[0,3],[5,0]]
        for (auto &i : buildings) {
            xPositions.push_back(pair<int, int>{i[0], -i[2]});
            xPositions.push_back(pair<int, int>{i[1], i[2]});
        }
        sort(xPositions.begin(), xPositions.end());
        heights.insert(0);
        int previous = 0;
        int current = 0;
        for (auto &i : xPositions) {
            if (i.second < 0) {
                heights.insert(-i.second);
            } else {
                heights.erase(heights.find(i.second));
            }
            current = *heights.rbegin();
            if (current != previous) {
                result.push_back(pair<int, int>{i.first, current});
                previous = current;
            }
        }
        return result;
    }
};
