/**
 * 此文件是 删除 BST 中的某个节点
 */
struct TreeNode {
    int val;            
    TreeNode *left;     
    TreeNode *right;   
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* remove(TreeNode* root, int value) {
    if (!root) return nullptr; // 空节点直接返回

    if (value < root->val) {
        root->left = remove(root->left, value); // 在左子树删除
    } else if (value > root->val) {
        root->right = remove(root->right, value); // 在右子树删除
    } else {
        // 找到目标节点
        if (!root->left) { // 左子树为空
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) { // 右子树为空
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            // 找右子树最小值替代当前节点
            TreeNode* successor = root->right;
            while (successor->left) successor = successor->left;
            root->val = successor->val;
            root->right = remove(root->right, successor->val); // 删除后继节点
        }
    }
    return root;
}
