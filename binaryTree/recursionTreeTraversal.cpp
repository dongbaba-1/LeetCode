#include<vector>
#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
vector<int> result;
void preorderTraversal(TreeNode* root) {
    if(root)
        result.push_back(root->val);
    else
        return;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
    inorderTraversal(root->left);
    if(root)
        result.push_back(root->val);
    else
        return;
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    if(root)
        result.push_back(root->val);
    else
        return;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
