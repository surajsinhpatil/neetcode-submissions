/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    void serializeHelper(TreeNode* node, stringstream &ss) {
        if (node == nullptr) {
            ss << "N ";
            return;
        }

        ss << node -> val << " ";
        serializeHelper(node -> left, ss);
        serializeHelper(node -> right, ss);
    }

    TreeNode* deserializeHelper(stringstream &ss) {
        string val;
        ss >> val;

        if (val == "N") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(val));

        node -> left = deserializeHelper(ss);
        node -> right = deserializeHelper(ss);
        return node;
    }
};
