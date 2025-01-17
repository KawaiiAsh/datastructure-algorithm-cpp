/**
 * 此文件是就 A 到 B 的距离
 * 1. 先找公共祖先
 * 2. 做出某个点的深度
 * 3. 公共祖先到 2 个点的距离，相加，就是 A 到 B 的距离
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// 公共祖先
TreeNode* findACL(TreeNode *root,int a,int b){
    if(!root) return nullptr;

    if(a < root->val && b < root->val){
        return findACL(root->left,a,b);
    }

    if(a > root->val && b > root->val){
        return findACL(root->right,a,b);
    }

    return root;
}
// 某个点的深度
int depth(TreeNode *root,int target){
    if(!root) return -1;

    if(target == root->val){
        return 0;
    }

    int d = (target < root->val) ? depth(root->left,target) : depth(root->right,target);

    return (d == -1) ? -1 : 1 + d;
}

int distence(TreeNode *root,int a, int b){
    TreeNode* acl = findACL(root,a,b);
    return depth(acl,a) + depth(acl,b);
}

// 完美的distence, 处理了边界
int perfectDistencce(TreeNode *root, int a, int b) {
    // 找到最近公共祖先 (LCA)
    TreeNode* acl = findACL(root, a, b);
    if (!acl) return -1; // 如果没有找到 LCA（理论上不应该发生），返回 -1

    // 计算从 LCA 到 a 和 b 的深度
    int depthA = depth(acl, a);
    int depthB = depth(acl, b);

    // 如果任意一个节点的深度为 -1，说明该节点不存在
    if (depthA == -1 || depthB == -1) return -1;

    // 返回两者深度之和
    return depthA + depthB;
}