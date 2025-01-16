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
int depthCorrect(TreeNode *root, const int &target) {
    if (!root) return -1;  // 空节点，返回 -1
    if (root->val == target) return 0;  // 找到目标节点，返回 0

    // 递归查找左右子树
    int subtree_depth = (target < root->val) 
                        ? depth(root->left, target) 
                        : depth(root->right, target);

    // 如果子树中未找到目标节点，返回 -1
    return (subtree_depth == -1) ? -1 : 1 + subtree_depth;
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
