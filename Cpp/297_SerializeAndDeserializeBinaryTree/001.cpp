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
        stringstream encodedTree;
        serialize(root, encodedTree);
        return encodedTree.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
private:
    TreeNode* deserialize(stringstream& ss) {
        string temp;
        ss >> temp;
        if (temp == "*") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(temp));
        node->left = deserialize(ss);
        node->right = deserialize(ss);
        return node;
    }
    void serialize(TreeNode* node, stringstream& encodedTree) {
        if (node == nullptr) {
            encodedTree << "* ";
            return;
        }
        encodedTree << node->val << " ";
        serialize(node->left, encodedTree);
        serialize(node->right, encodedTree);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));