struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){};
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode* nextPtr):val(x), next(nextPtr){};
    /* data */
};


ListNode* reverseList(ListNode* head) {
    if(!head){
        return nullptr;//首先判断head是否为空。如果为空直接返回null
    }
    if(!head->next){
        return head;//若只有一个元素，则直接返回head
    }
    else{
        ListNode *p,*q,*r;
        p = head;
        q = p->next;
        r = q->next;//
        head->next = nullptr;
        while(q){
            q->next = p;
            p = q;
            q = r;
            if(r){
                r = r->next;
            }
        }
        head = p;
    }
    return head;

}