#define TREENODE_H

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left_child, TreeNode* right_child):val(x),left(left_child),right(right_child){}
};