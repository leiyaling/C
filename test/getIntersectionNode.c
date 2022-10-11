struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tailA=headA;
    struct ListNode *tailB=headB;
 
    int lenA=1;
    while(tailA->next)
    {
        ++lenA;
        tailA=tailA->next;
    }
 
     int lenB=1;
     while(tailB->next)
    {
        ++lenB;
        tailB=tailB->next;
    }
 
    //不相交
    if(tailA!=tailB)
        return NULL;
 
    //长的链表先走差距步，再同时走找交点
    int gap=abs(lenA-lenB);//abs--求绝对值
    struct ListNode *longList=headA;
    struct ListNode *shortList=headB;
    if(lenA<lenB)
    {
        longList=headB;
        shortList=headA;
    }
 
    while(gap--)
    {
        longList=longList->next;
    }
    while(longList!=shortList)
    {
        longList=longList->next;
        shortList=shortList->next;
    }
    return longList;
}