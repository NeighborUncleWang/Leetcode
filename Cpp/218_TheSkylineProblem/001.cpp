class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> heights;
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
        for (vector<int>& building : buildings) {
            heights.emplace_back(building[0], -building[2]);
            heights.emplace_back(building[1], building[2]);
        }
        sort(heights.begin(), heights.end());
        multiset<int, greater<int>> heap;
        heap.insert(0);
        int previous = 0;
        vector<pair<int, int>> result;
        for (auto& height : heights) {
            if (height.second < 0) {
                heap.insert(-height.second);
            } else {
                //这里不要用heap.erase(height.second)
                //否则会把所有value为height.second的元素都删除
                heap.erase(heap.find(height.second));
            }
            int current = *heap.begin();
            if (current != previous) {
                result.emplace_back(height.first, current);
                previous = current;
            }
        }
        return result;
    }
};