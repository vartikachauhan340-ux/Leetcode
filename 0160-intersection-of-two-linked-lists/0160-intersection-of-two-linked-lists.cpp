/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a1= headA;
        ListNode* b1= headB;
        while(a1!= b1){
            if(a1 == NULL){
                a1 = headB;
            } else{
                a1= a1->next;
            }
            if(b1 == NULL){
                b1= headA;
            } else{
                b1= b1->next;
            }
        }
        return b1;
    }
};