class Vector2D {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> iteratorsQueue;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (vector<int>& vec : vec2d) {
            if (!vec.empty()) {
                iteratorsQueue.emplace(vec.begin(), vec.end());
            }
        }
    }

    int next() {
        auto& current = iteratorsQueue.front().first;
        auto& end = iteratorsQueue.front().second;
        int result = *current;
        if (++current == end) {
            iteratorsQueue.pop();
        }
        return result;
    }

    bool hasNext() {
        return !iteratorsQueue.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */