#include "TreeNode.h"
using namespace std;

//226

void swapChildren(TreeNode* node){
    if(node->left != nullptr && node->right != nullptr){
        TreeNode* temp = node->right;
        node->right = node->left;
        node->left = temp;
    }
    if(node->left != nullptr && node->right == nullptr){
        node->right = node->left;
        node->left = nullptr;
    }
    else if(node->right != nullptr && node->left == nullptr){
        node->left = node->right;
        node->right = nullptr;
    }
    
}

TreeNode* invertTree(TreeNode* root) {
    //TreeNode *p,*q = root;
    if(root == nullptr)
        return root;
    swapChildren(root);
    if(root->left != nullptr)
        invertTree(root->left);
    if(root->right != nullptr)
        invertTree(root->right);
    return root;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    root->left = left;
    invertTree(root);
    return 0;
}
