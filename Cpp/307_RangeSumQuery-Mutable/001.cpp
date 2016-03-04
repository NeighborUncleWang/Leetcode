struct SegmentTreeNode {
    int start;
    int end;
    SegmentTreeNode* left = nullptr;
    SegmentTreeNode* right = nullptr;
    int sum;
    SegmentTreeNode(int start, int end, int sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
    }
};
class NumArray {
private:
    SegmentTreeNode* root;
    int size;
public:
    SegmentTreeNode* constructTree (int start, int end, vector<int>& nums) {
        if (start > end) {
            return nullptr;
        } else if (start == end) {
            return new SegmentTreeNode(start, end, nums[start]);
        }
        int middle = start + (end - start) / 2;
        auto current = new SegmentTreeNode(start, end, 0);
        current->left = constructTree(start, middle, nums);
        current->right = constructTree(middle + 1, end, nums);
        current->sum = current->left->sum + current->right->sum;
        return current;
    }
    void updateTree(SegmentTreeNode* current, int index, int val) {
        if (index < current->start || index > current->end) {
            return;
        } else if (index == current->start && index == current->end) {
            current->sum = val;
            return;
        }
        updateTree(current->left, index, val);
        updateTree(current->right, index, val);
        current->sum = current->left->sum + current->right->sum;
    }
    
    int getSum(SegmentTreeNode* current, int i, int j) {
        if (current->end < i || current->start > j) {
            return 0;
        } else if (current->start >= i && current->end <= j) {
            return current->sum;
        }
        return getSum(current->left, i, j) + getSum(current->right, i, j);
    }
    NumArray(vector<int> &nums) {
        size = nums.size();
        root = constructTree(0, size - 1, nums);
    }

    void update(int i, int val) {
        updateTree(root, i, val);
    }

    int sumRange(int i, int j) {
        return getSum(root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);