//https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        ListNode *first, *second;
        first = second = head;
        
        if(first == NULL or second->next == NULL) return false;
        second = second->next;
        
        while(first != NULL && second != NULL){
            if(first == second) return true;
            first = first->next ;
            second = second->next ;
            if(second == NULL) return false;
            second = second->next ;
        }
        
        return false;
    }
};
