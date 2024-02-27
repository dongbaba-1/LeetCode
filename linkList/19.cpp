struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //设置虚拟头节点让删除头节点与其余节点一致
    ListNode* virtualHead = new ListNode();
    virtualHead->next = head;
    ListNode *slow,*fast;
    slow = virtualHead;
    fast = virtualHead;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;//快指针往前走n个身位
    }
    fast = fast->next;//让快指针再走一个，使得慢指针在待删节点的前一个位置
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }
    //此时快指针指空，删除所指向节点
    ListNode* temp = slow->next;
    slow->next = slow->next->next;

    temp->next = nullptr;
    delete(temp);
    return virtualHead->next;
}