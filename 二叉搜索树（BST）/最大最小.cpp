/**
 * 此文件是找出 BST 中的 Max 和 Min 节点
 * 1. 最大的值一定在最右边
 * 2. 最小的值一定在最左边
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* findMax(TreeNode* root){
    if(!root || !root->right) return root;
    return findMax(root->right);
}

TreeNode* findMin(TreeNode* root){
    if(!root || !root->right) return root;
    return findMin(root->left);
}