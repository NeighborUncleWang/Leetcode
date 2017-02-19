class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //排序就是为了让后面插入result的人不会影响前面已经插入好的队列
        //相同height让a.second小的排前面是因为小的插完后面大的插入进去不会影响之前小的
        //反之则不然
        sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first || a.first == b.first && a.second < b.second;
        });
        vector<pair<int, int>> result;
        for (auto person : people) {
            result.insert(result.begin() + person.second, person);
        }
        return result;
    }
};