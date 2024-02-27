struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA=0,lengthB=0;
    ListNode *p,*q;
    p = headA;
    q = headB;
    while(p){
        lengthA++;
        p = p->next;
    }
    while(q){
        lengthB++;
        q = q->next;
    }
    p = headA;
    q = headB;//q,p重新指回各自头节点
    if(lengthA>=lengthB){
        int chazhi = lengthA - lengthB;
        while(chazhi>0){
            p = p->next;
            chazhi--;
        }
    }
    else{
        int chazhi = lengthB - lengthA;
        while(chazhi>0){
            q = q->next;
            chazhi--;
        }
    }
    //现在q、p在同一起跑线
    while(q){
        if(q == p){
            return q;
        }
        q = q->next;
        p = p->next;
    }
    return nullptr;
}