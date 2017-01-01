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
        stringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
private:
    TreeNode* deserializeHelper(iostream& ss) {
        string value;
        ss >> value;
        if (value == "*") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(value));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
    void serializeHelper(TreeNode* node, stringstream& ss) {
        if (node == nullptr) {
            ss << "* ";
            return;
        }
        ss << node->val << " ";
        serializeHelper(node->left, ss);
        serializeHelper(node->right, ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));