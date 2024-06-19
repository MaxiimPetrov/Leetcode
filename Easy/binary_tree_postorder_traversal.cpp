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

std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> traversal_nodes;

    std::function<void(TreeNode*)> postorderTraversalHelper = [&](TreeNode* node) {
            if(node == nullptr) {
            return;
        }
        postorderTraversalHelper(node->left);
        postorderTraversalHelper(node->right);

        traversal_nodes.push_back(node->val);

    };

    postorderTraversalHelper(root);

    return traversal_nodes;
}