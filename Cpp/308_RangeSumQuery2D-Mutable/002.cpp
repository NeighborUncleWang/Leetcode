struct QuadTreeNode {
    int row1 = 0;
    int col1 = 0;
    int row2 = 0;
    int col2 = 0;
    int sum = 0;
    vector<QuadTreeNode*> children = vector<QuadTreeNode*>(4, nullptr);
    QuadTreeNode(int row1, int col1, int row2, int col2, int sum) {
        this->row1 = row1;
        this->row2 = row2;
        this->col1 = col1;
        this->col2 = col2;
        this->sum = sum;
    }
};
class NumMatrix {
private:
    QuadTreeNode* root;
    QuadTreeNode* BuildQuadTree(vector<vector<int>>& matrix,
    int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2) {
            return nullptr;
        } else if (row1 == row2 && col1 == col2) {
            return new QuadTreeNode(row1, col1, row2, col2, matrix[row1][col1]);
        }
        QuadTreeNode* node = new QuadTreeNode(row1, col1, row2, col2, 0);
        int middleRow = row1 + (row2 - row1) / 2;
        int middleColumn = col1 + (col2 - col1) / 2;
        node->children[0] = BuildQuadTree(matrix, row1, col1, middleRow, middleColumn);
        node->children[1] = BuildQuadTree(matrix, row1, middleColumn + 1, middleRow, col2);
        node->children[2] = BuildQuadTree(matrix, middleRow + 1, col1, row2, middleColumn);
        node->children[3] = BuildQuadTree(matrix, middleRow + 1, middleColumn + 1, row2, col2);
        for (auto child : node->children) {
            if (child != nullptr) {
                node->sum += child->sum;
            }
        }
        return node;
    }
    void updateHelper(QuadTreeNode* node, int row, int col, int val) {
        if (node == nullptr || row < node->row1 || row > node->row2
            || col < node->col1 || col > node->col2) {
            return;
        } else if (row == node->row1 && node->row1 == node->row2
        && col == node->col1 && node->col1 == node->col2) {
            node->sum = val;
            return;
        }
        for (QuadTreeNode* child : node->children) {
            updateHelper(child, row, col, val);
        }
        node->sum = 0;
        for (QuadTreeNode* child : node->children) {
            if (child) {
                node->sum += child->sum;
            }
        }
    }
    int sumRegionHelper(QuadTreeNode* node, int row1, int col1, int row2, int col2) {
        if (node == nullptr || node->row1 > row2 || node->col1 > col2
            || node->row2 < row1 || node->col2 < col1) {
            return 0;
        } else if (node->row1 >= row1 && node->col1 >= col1
                   && node->row2 <= row2 && node->col2 <= col2) {
            return node->sum;
        }
        int sum = 0;
        for (auto child : node->children) {
            sum += sumRegionHelper(child, row1, col1, row2, col2);
        }
        return sum;
    }
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        root = BuildQuadTree(matrix, 0, 0, rowSize - 1, columnSize - 1);
    }

    void update(int row, int col, int val) {
        updateHelper(root, row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRegionHelper(root, row1, col1, row2, col2);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);