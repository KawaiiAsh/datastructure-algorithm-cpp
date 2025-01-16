/**
 * 此文件是关于查找某个元素在BST
 * 1. 返回 对应的节点指针
 * 2. 返回 true or false
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value):val(value),left(nullptr),right(nullptr){}
};

/**
 * 实现1. 查找目标，返回对应的Node
 * 1. 如果 root 节点为空或找到了目标值
 * 2. 如果目标值小于当前节点值，则继续在左子树中查找
 * 3. 如果目标值大于当前节点值，则继续在右子树中查找
 */
TreeNode* nodeSearchReturnNode(TreeNode* root,const int &target){
    if(root == nullptr || root->val == target ){
        return root;
    }

    if(target < root->val){
        return nodeSearchReturnNode(root->left,target);
    }

    return nodeSearchReturnNode(root->right,target);
}

/**
 * 实现2，查找目标，返回 true or false
 * 1. 如果 root 是 nullptr，直接 false
 * 2. 如果 root 是 target，直接true
 * 3. 如果 target 小于 根，那就左子树
 * 4. 如果 target 大于 根，那就右子树
 */
bool nodeSearchReturnBool(TreeNode* root,const int &target){
    if(root == nullptr){
        return false;
    }    
    if(root->val == target){
        return true;
    }

    if(target < root->val){
        return nodeSearchReturnBool(root->left,target);
    }

    return nodeSearchReturnBool(root->right,target);
}