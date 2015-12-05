class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        xPosition = 0;
        yPosition = 0;
        matrix = vec2d;
        validateIndices();
    }
    void validateIndices(void) {
        while (xPosition < matrix.size() && yPosition >= matrix[xPosition].size()) {
            ++xPosition;
            yPosition = 0;
        }
    }
    int next() {
        int temp = matrix[xPosition][yPosition];
        ++yPosition;
        validateIndices();
        return temp;
    }

    bool hasNext() {
        //or we can call validateIndices() here
        return xPosition < matrix.size();
    }
private:
    int xPosition;
    int yPosition;
    vector<vector<int>> matrix;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */