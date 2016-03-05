class Vector2D {
private:
    vector<vector<int>>::iterator current;
    vector<vector<int>>::iterator end;
    int index = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        current = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        hasNext();
        return (*current)[index++];
    }

    bool hasNext() {
        while (current != end && index == current->size()) {
            ++current;
            index = 0;
        }
        return current != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */