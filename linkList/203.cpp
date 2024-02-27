struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *vistualHead = new ListNode();
    vistualHead->next = head;
    ListNode *p,*q;
    p = vistualHead;
    q = vistualHead;
    while(q){
        if(q->next->val == val){
            p = q->next;
            q->next = p->next;
            p->next = nullptr;
            delete p;
        }
        if(q->next == nullptr || q->next->val != val){
            q = q->next;
        }
    }
    return vistualHead->next;

}
