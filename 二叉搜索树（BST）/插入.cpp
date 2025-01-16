/**
 * 此文件是关于将新值插入二叉搜索树
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value):val(value),left(nullptr),right(nullptr){}
};

/**
 * 1. 判断 root 是否为空，如果是，插入 root
 * 2. 如果 num < root，插左
 *    如果 num > root，插右
 * 3. 如果 左为空，那么 插入
 *    如果 右为空，那么 插入
 * 4. 如果都不为空，继续递归
 */
TreeNode* insert(TreeNode* root,const int &val){
    if(!root){
        return new TreeNode(val); // 当前节点为空时，创建新节点
    }

    if(val < root->val){
        root->left = insert(root->left,val); // 插入左子树
    }

    if(val > root->val){
        root->right = insert(root->right,val); // 插入右子树
    }

    return root; // 返回当前节点
}