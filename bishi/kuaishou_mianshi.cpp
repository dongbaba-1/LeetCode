#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
};


vector<vector<int> > layer(TreeNode* head){
    vector<vector<int> > result;
    queue<TreeNode*> queue;
    //头节点对队列
    queue.push(head);
    int current_layer_num = 1;
    int next_layer_num = 0;
    vector<int> layer_node;
    //当队列不为空时
    while(!queue.empty()){
        TreeNode* p = queue.front();
        //vector<int> layer_node;
        layer_node.push_back(p->value);
        queue.pop();//队首元素弹出
        current_layer_num--;
        if(p->left){//左子树不为空，左子树入队列
            queue.push(p->left);
            next_layer_num++;
        }
        if(p->right){
            queue.push(p->right);
            next_layer_num++;
        }
        //当层的数目为0时，表示一层的节点已遍历完
        if(current_layer_num == 0){
            result.push_back(layer_node);
            current_layer_num = next_layer_num;
            next_layer_num = 0;
            layer_node.clear();
        }
    }
    return result;
}

int main() {

    TreeNode* node1 = new TreeNode();
    node1->value = 3;
    TreeNode* node2 = new TreeNode();
    node2->value = 9;
    TreeNode* node3 = new TreeNode();
    node3->value = 20;
    TreeNode* node4 = new TreeNode();
    node4->value = 15;
    TreeNode* node5 = new TreeNode();
    node5->value = 7;
    
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    vector<vector<int> > result = layer(node1);

    for(int i = 0;i <result.size();i++){
        for(int j = 0;j < result[i].size();j++){
            cout <<result[i][j]<<" ";
        }
        cout<<endl;
    }


}