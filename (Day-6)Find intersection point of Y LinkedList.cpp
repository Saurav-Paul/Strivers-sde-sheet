//https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
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
        
        int lenA = 0, lenB = 0;
        ListNode* temp = headA;
        
        while(temp != NULL){
            lenA ++;
            temp = temp->next ;
        }
        
        temp = headB;
        while(temp != NULL){
            lenB ++;
            temp = temp->next ;
        }

        
        if(lenB > lenA) swap(headA,headB) ;
        int diff = abs(lenA - lenB) ;
        
        while(diff){
            diff --;
            headA = headA->next ;
        }
        
        while(headA != NULL && headB != NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
