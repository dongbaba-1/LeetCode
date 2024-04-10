#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//102
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> queue;
    vector<vector<int> > result;
    if(!root) //首先判空
        return result;
    int current_layer_node_num = 0;//存放当前层的节点数量，便于分辨层与层
    int next_layer_node_num = 0;//存放下一层的节点数量，便于分辨层与层
    queue.push(root);//根节点先入队列
    vector<int> layer_nodes;//存放每一层的节点
    current_layer_node_num = 1;
    while (!queue.empty())
    {
        TreeNode* p = queue.front();
        queue.pop();//弹出队列
        layer_nodes.push_back(p->val);
        current_layer_node_num--;
        if(p->left != nullptr){
            queue.push(p->left);
            next_layer_node_num++;
        }
        if(p->right != nullptr){
            queue.push(p->right);
            next_layer_node_num++;
        }
        if(current_layer_node_num == 0){
            result.push_back(layer_nodes);
            layer_nodes.clear();
            current_layer_node_num = next_layer_node_num;
            next_layer_node_num = 0;
        }
    }
    return result;

}


//107
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> queue;
    vector<vector<int> > result;
    if(!root) //首先判空
        return result;
    int current_layer_node_num = 0;//存放当前层的节点数量，便于分辨层与层
    int next_layer_node_num = 0;//存放下一层的节点数量，便于分辨层与层
    queue.push(root);//根节点先入队列
    vector<int> layer_nodes;//存放每一层的节点
    current_layer_node_num = 1;
    while (!queue.empty())
    {
        TreeNode* p = queue.front();
        queue.pop();//弹出队列
        layer_nodes.push_back(p->val);
        current_layer_node_num--;
        if(p->left != nullptr){
            queue.push(p->left);
            next_layer_node_num++;
        }
        if(p->right != nullptr){
            queue.push(p->right);
            next_layer_node_num++;
        }
        if(current_layer_node_num == 0){
            result.push_back(layer_nodes);
            layer_nodes.clear();
            current_layer_node_num = next_layer_node_num;
            next_layer_node_num = 0;
        }
    }
    for (int i = 0; i < result.size()/2; i++)
    {
        auto low_iter = result.begin();
        auto high_iter = result.end() - 1;
        vector<int> temp;
        temp = *low_iter;
        *low_iter = *high_iter;
        *high_iter = temp;
        low_iter++;
        high_iter--;
    }
    
    return result;
}

//199
vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> queue;
    vector<vector<int> > result;
    vector<int> result_right_view;
    if(!root) //首先判空
        return result_right_view;
    int current_layer_node_num = 0;//存放当前层的节点数量，便于分辨层与层
    int next_layer_node_num = 0;//存放下一层的节点数量，便于分辨层与层
    queue.push(root);//根节点先入队列
    vector<int> layer_nodes;//存放每一层的节点
    current_layer_node_num = 1;
    while (!queue.empty())
    {
        TreeNode* p = queue.front();
        queue.pop();//弹出队列
        layer_nodes.push_back(p->val);
        current_layer_node_num--;
        if(p->left != nullptr){
            queue.push(p->left);
            next_layer_node_num++;
        }
        if(p->right != nullptr){
            queue.push(p->right);
            next_layer_node_num++;
        }
        if(current_layer_node_num == 0){
            result_right_view.push_back(layer_nodes.back());
            result.push_back(layer_nodes);
            layer_nodes.clear();
            current_layer_node_num = next_layer_node_num;
            next_layer_node_num = 0;
        }
    }
    return result;
}

//637
vector<double> averageOfLevels(TreeNode* root) {

}

//104
int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    queue<TreeNode*> queue;
    int maxDepth = 0;
    int current_layer_nodes = 0;
    int next_layer_nodes = 0;
    queue.push(root);
    current_layer_nodes = 1;
    maxDepth++;
    while (!queue.empty())
    {
        TreeNode* p = queue.front();
        queue.pop();
        current_layer_nodes--;
        if(p->left != nullptr){
            queue.push(p->left);
            next_layer_nodes++;
        }
        if(p->right != nullptr){
            queue.push(p->right);
            next_layer_nodes++;
        }
        if(current_layer_nodes == 0 && next_layer_nodes != 0){
            maxDepth++;
            current_layer_nodes = next_layer_nodes;
            next_layer_nodes = 0;
        }
    }
    return maxDepth;
    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}





