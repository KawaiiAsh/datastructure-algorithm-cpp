/**
 * 此文件是关于 BST 中 A 和 B 的公共祖先
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

/**
 * 1. 判断根是否存在
 * 2. 如果 a 和 b 都小于 root，就在左子树
 * 3. 如果 a 和 b 都大于 root，就在右子树
 * 4. 否则祖先一定是 root
 */
TreeNode* findLCA(TreeNode *root,int a, int b){
    if(!root) return nullptr;

    if(a < root->val && b < root->val){
        // 一定在左子树
        return findLCA(root->left,a,b);
    }

    if(a > root->val && b > root->val){
        // 一定在右子树
        return findLCA(root->right,a,b);
    }

    return root;
}