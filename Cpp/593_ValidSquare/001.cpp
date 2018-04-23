class Solution {
private:
    int dist(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> set{dist(p1, p2), dist(p2, p3), dist(p3, p4), dist(p1, p4), dist(p1, p3), dist(p2, p4)};
        return set.find(0) == set.end() && set.size() == 2;
    }
};
