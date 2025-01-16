/**
 * 此文件包括
 * 1. 前序遍历 (根 -> 左 -> 右)
 * 2. 中序遍历 (左 -> 根 -> 右)
 * 3. 后序遍历 (左 -> 右 -> 根)
 */
#include <vector>
using namespace std;

struct TreeNode {
    int val;            
    TreeNode *left;     
    TreeNode *right;   
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

/**
 * 前序遍历函数 (根 -> 左 -> 右)
 */
void preorderTraversal(TreeNode *root, vector<int> &result) {
    if (!root) return;                          // 如果当前节点为空，直接返回
    result.push_back(root->val);                // 访问根节点，存入结果
    preorderTraversal(root->left, result);      // 递归遍历左子树
    preorderTraversal(root->right, result);     // 递归遍历右子树
}

/**
 * 中序遍历函数 (左 -> 根 -> 右)
 */
void inorderTraversal(TreeNode *root, vector<int> &result) {
    if (!root) return;                          // 如果当前节点为空，直接返回
    inorderTraversal(root->left, result);       // 递归遍历左子树
    result.push_back(root->val);                // 访问根节点，存入结果
    inorderTraversal(root->right, result);      // 递归遍历右子树
}

/**
 * 后序遍历函数 (左 -> 右 -> 根)
 */
void postorderTraversal(TreeNode *root, vector<int> &result) {
    if (!root) return;                          // 如果当前节点为空，直接返回
    postorderTraversal(root->left, result);     // 递归遍历左子树
    postorderTraversal(root->right, result);    // 递归遍历右子树
    result.push_back(root->val);                // 访问根节点，存入结果
}
