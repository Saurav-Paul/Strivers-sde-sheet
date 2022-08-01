//https://leetcode.com/problems/middle-of-the-linked-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* pointer_1;
        ListNode* pointer_2;
        
        pointer_1 = head;
        pointer_2 = head;
        
        while(pointer_2!=NULL and pointer_2->next != NULL){
            pointer_1 = pointer_1->next ;
            pointer_2 = pointer_2->next ;
            
            if(pointer_2 != NULL) pointer_2 = pointer_2->next ;
        }
        
        return pointer_1 ;
    }
};
