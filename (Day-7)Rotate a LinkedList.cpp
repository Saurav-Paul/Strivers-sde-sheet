//https://leetcode.com/problems/rotate-list/
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
    int findLength(ListNode *head){
        int cnt = 0;
        while(head != NULL){
            ++ cnt ;
            head = head->next;
        }
        return cnt ;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL) return head ;
        
        
        int length = findLength(head) ;
        k = k % length;
        
        if(k == 0) return head ;
        
        int rotate = length - k -1;
        
        ListNode* newHead = head ;
        while(rotate){
            newHead = newHead->next ;
            -- rotate ;
        }
        
        ListNode *temp = newHead->next ;
        newHead->next = NULL;
        
        newHead = temp ;
        
        while(temp->next != NULL){
            temp = temp->next ;
        }
        
        temp->next = head ;
        
        return newHead;
    }
};
