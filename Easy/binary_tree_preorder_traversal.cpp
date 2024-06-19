#include <vector>
#include <functional>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> traversal_nodes;

    std::function<void(TreeNode*)> preorderTraversalHelper = [&](TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        traversal_nodes.push_back(node->val);

        preorderTraversalHelper(node->left);
        preorderTraversalHelper(node->right);
    };

    preorderTraversalHelper(root);

    return traversal_nodes;

}