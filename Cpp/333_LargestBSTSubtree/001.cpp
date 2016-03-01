/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int maxSize = 0;
        helper(root, maxSize);
        return maxSize;
    }
private:
    struct Result {
        int size;
        long long min;
        long long max;
        Result(int size, long long min, long long max) {
            this->size = size;
            this->min = min;
            this->max = max;
        }
    };
    Result helper(TreeNode* current, int& maxSize) {
        //min和max之所以用long long类型是因为假如这道题目要求
        //valid binary search tree不能有duplicates(像Q98.Validate Binary Search Tree一样)
        //那么直接用INT_MAX和INT_MIN当[INT_MAX]的时候就会出错
        //因为在判断current->val和left.max,right.min比较会出现相等的情况
        //如果题目允许valid binary tree里面存在duplicates,就像CLRS中说的
        //只要left subtree all <= root <= right subtree all
        //那就可以用INT_MAX和INT_MIN
        //这题这个都不说，日！
        //OJ上用INT_MAX和INT_MIN当输入是[INT_MAX]时输出是1符合正确答案
        //但是CLION上跑输出又是0，TMD搞什么鬼
        if (current == nullptr) return Result(0, LLONG_MAX, LLONG_MIN);
        auto left = helper(current->left, maxSize);
        auto right = helper(current->right, maxSize);
        if (left.size < 0 || right.size < 0 || current->val <= left.max || current->val >= right.min) {
            return Result(-1, 0, 0);
        }
        int size = left.size + right.size + 1;
        maxSize = max(maxSize, size);
        return Result(size, min(left.min, (long long)current->val), max(right.max, (long long)current->val));
    }
};