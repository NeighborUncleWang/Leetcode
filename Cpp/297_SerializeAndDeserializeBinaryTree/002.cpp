/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encodedTree;
        serialize(root, encodedTree);
        return encodedTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return deserialize(data, start);
    }
private:
    TreeNode* deserialize(string& s, int& start) {
        int end = s.find(' ', start);
        string temp = s.substr(start, end - start);
        start = end + 1;
        if (temp == "*") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(temp));
        node->left = deserialize(s, start);
        node->right = deserialize(s, start);
        return node;
    }
    void serialize(TreeNode* node, string& encodedTree) {
        if (node == nullptr) {
            encodedTree += "* ";
            return;
        }
        encodedTree += to_string(node->val) + " ";
        serialize(node->left, encodedTree);
        serialize(node->right, encodedTree);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));