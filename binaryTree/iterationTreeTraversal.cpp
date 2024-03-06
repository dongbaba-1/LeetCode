#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};



vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> stack;
    vector<int> result;
    if(root){//根节点入栈
        stack.push(root);
        result.push_back(root->val);
    }
    while(!stack.empty()){
        root = stack.top();
        while(root->left){
            stack.push(root->left);
            result.push_back(root->left->val);
            TreeNode* pre = root;
            root = root->left;
            pre->left = nullptr;//断链
        }
        //左子树为空，出栈
        root = stack.top();
        stack.pop();
        if(root->right){
            stack.push(root->right);
            result.push_back(root->right->val);
            root = root->right;
        }
    }
    return result;
}

vector<int> preorderTraversal2(TreeNode* root){
    stack<TreeNode*> stack;
    vector<int> result;
    if(root){//根节点入栈
        stack.push(root);
    }
    while(!stack.empty()){
        TreeNode* node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if(node->right)
            stack.push(node->right);
        if(node->left)
            stack.push(node->right);
    }
    return result;
}

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> stack;
    vector<int> result;
    if(root){//根节点入栈
        stack.push(root);
    }
    while(!stack.empty()){
        root = stack.top();
        while(root->left){
            stack.push(root->left);
            //result.push_back(root->left->val);
            TreeNode* pre = root;
            root = root->left;
            pre->left = nullptr;//断链
        }
        //左子树为空，出栈
        root = stack.top();
        result.push_back(root->val);
        stack.pop();
        if(root->right){
            stack.push(root->right);
            root = root->right;
        }
    }
    return result;
}

vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stack;
    vector<int> result;
    if(root){
        stack.push(root);
    }
    while(!stack.empty()){
        TreeNode* node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if(node->left)
            stack.push(node->left);
        if(node->right)
            stack.push(node->right);

    }
    reverse(result.begin(),result.end());
    return result;
}
