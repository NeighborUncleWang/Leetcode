class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> iteratorsQueue;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            iteratorsQueue.emplace(v1.begin(), v1.end());
        }
        if (!v2.empty()) {
            iteratorsQueue.emplace(v2.begin(), v2.end());
        }
    }

    int next() {
        auto currentBegin = iteratorsQueue.front().first;
        auto currentEnd = iteratorsQueue.front().second;
        iteratorsQueue.pop();
        if (currentBegin + 1 != currentEnd) {
            iteratorsQueue.emplace(currentBegin + 1, currentEnd);
        }
        return *currentBegin;
    }

    bool hasNext() {
        return !iteratorsQueue.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */