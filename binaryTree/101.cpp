#include "TreeNode.h"

bool compare(TreeNode* left,TreeNode* right){
    if(left == nullptr && right != nullptr)
        return false;
    else if(left != nullptr && right == nullptr)
        return false;
    else if(left == nullptr && right== nullptr)
        return true;
    else if(left->val != right->val)
        return false;
    // 此时就是：左右节点都不为空，且数值相同的情况
    // 此时才做递归，做下一层的判断
    bool outside = compare(left->left,right->right);
    bool inside = compare(left->right,right->left);
    bool isSame = outside && inside;
    return isSame;
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr)
        return true;
    return compare(root->left,root->right);
}