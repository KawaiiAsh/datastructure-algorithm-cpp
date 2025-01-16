/**
 * 此文件是关于 Node 的 depth
 * 节点的深度是指从根节点到目标节点的路径长度
 * 根节点的深度为 0
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// 正确的实现方法
int depthCorrect(TreeNode *root, int target) {
    if (!root) return -1;  // 空节点，返回 -1
    if (root->val == target) return 0;  // 找到目标节点，返回 0

    // 递归查找左右子树
    int depth = (target < root->val) 
                        ? depthCorrect(root->left, target) 
                        : depthCorrect(root->right, target);
    
    // 如果子树中未找到目标节点，返回 -1
    return (depth == -1) ? -1 : 1 + depth;
}

// 深度作为参数
int getDepth(TreeNode* root, int target, int depth) {
    if (!root) return -1; // 如果节点为空，返回 -1，表示未找到
    if (root->val == target) return depth; // 找到目标节点，返回当前深度
    if (target < root->val) {
        return getDepth(root->left, target, depth + 1); // 递归查找左子树，深度加 1
    }
    return getDepth(root->right, target, depth + 1); // 递归查找右子树，深度加 1
}

// W24 final 考试答案，实际上有问题
int depth(TreeNode *root,const int &target){
    if(root -> val == target) return 0;

    if(target < root->val){
        return 1 + depth(root->left,target);
    }else{
        return 1 + depth(root->right,target);
    }
}
