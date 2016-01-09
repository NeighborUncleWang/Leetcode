struct SegmentTreeNode {
    int start;
    int end;
    int sum = 0;
    SegmentTreeNode *leftChild = nullptr;
    SegmentTreeNode *rightChild = nullptr;

    SegmentTreeNode(int start, int end, int sum = 0,
                    SegmentTreeNode *left = nullptr, SegmentTreeNode *right = nullptr) {
        this->start = start;
        this->end = end;
        leftChild = left;
        rightChild = right;
        this->sum = sum;
    }
};

class SegmentTree {
private:
    SegmentTreeNode *root;

    SegmentTreeNode *BuildSegmentTree(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        } else if (start == end) {
            return new SegmentTreeNode(start, end, nums[start]);
        } else {
            int middle = start + (end - start) / 2;
            SegmentTreeNode *node = new SegmentTreeNode(start, end);
            node->leftChild = BuildSegmentTree(nums, start, middle);
            node->rightChild = BuildSegmentTree(nums, middle + 1, end);
            node->sum = node->leftChild->sum + node->rightChild->sum;
            return node;
        }
    }

    void updateHelper(SegmentTreeNode *node, int i, int val) {
        if (i < node->start || i > node->end) {
            return;
        } else if (i == node->start && i == node->end) {
            node->sum = val;
            return;
        }
        updateHelper(node->leftChild, i, val);
        updateHelper(node->rightChild, i, val);
        node->sum = node->leftChild->sum + node->rightChild->sum;
        return;
    }

    int sumRangeHelper(SegmentTreeNode *node, int i, int j) {
        if (j < node->start || i > node->end) {
            return 0;
        } else if (node->start >= i && node->end <= j) {
            return node->sum;
        } else {
            return sumRangeHelper(node->leftChild, i, j)
                   + sumRangeHelper(node->rightChild, i, j);
        }
    }

public:
    SegmentTree(vector<int> &nums) {
        int n = nums.size();
        root = BuildSegmentTree(nums, 0, n - 1);
    }

    void update(int i, int val) {
        updateHelper(root, i, val);
    }

    int sumRange(int i, int j) {
        return sumRangeHelper(root, i, j);
    }
};

class NumArray {
private:
    SegmentTree tree;
public:
    NumArray(vector<int> &nums) : tree(nums) { }

    void update(int i, int val) {
        tree.update(i, val);
    }

    int sumRange(int i, int j) {
        return tree.sumRange(i, j);
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);