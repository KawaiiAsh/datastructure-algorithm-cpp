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

// 前序遍历 (根 -> 左 -> 右)
vector<int> preorderTraversal(TreeNode *root) {
    if (!root) return {}; // 空树返回空向量
    vector<int> result;
    result.push_back(root->val); // 访问根节点

    // 遍历左子树
    vector<int> left = preorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    // 遍历右子树
    vector<int> right = preorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

// 中序遍历 (左 -> 根 -> 右)
vector<int> inorderTraversal(TreeNode *root) {
    if (!root) return {}; // 空树返回空向量
    vector<int> result;

    // 遍历左子树
    vector<int> left = inorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    // 访问根节点
    result.push_back(root->val);

    // 遍历右子树
    vector<int> right = inorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

// 后序遍历 (左 -> 右 -> 根)
vector<int> postorderTraversal(TreeNode *root) {
    if (!root) return {}; // 空树返回空向量
    vector<int> result;

    // 遍历左子树
    vector<int> left = postorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    // 遍历右子树
    vector<int> right = postorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    // 访问根节点
    result.push_back(root->val);

    return result;
}
