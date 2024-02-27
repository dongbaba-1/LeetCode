struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if(!head){
        return nullptr;
    }
    if(!head->next){
        return head;
    }
    else{
        ListNode *pre,*cur,*temp;
        pre = head;
        cur = head->next;
        temp = cur->next;
        head= cur;
        while(cur){
            cur->next = pre;
            if(temp && temp->next)
                pre->next = temp->next;//如果temp->next不空，则直接指向
            else if (temp)
                pre->next = temp;//若temp->next空但temp不空，则指向temp
            else{
                pre->next = nullptr;
                //若直接temp为空，说明是偶数个节点，直接指向空,也就意味着后面没有节点了
                break;//跳出循环
            }
            pre = temp;
            cur = pre->next;//节点数为奇数的情况使得赋值后的cur为空，因此cur作为while判断
            if(cur)
                temp = cur->next;
        }
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* node1 = new ListNode(1,node2);
    ListNode* head = node1;
    ListNode* reverseList = swapPairs(head);
    return 0;
}
