//https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    int findLen(ListNode *head){
        int cnt = 0;
        ListNode *temp = head;
        while(temp != NULL){
            cnt ++;
            temp = temp->next ;
        }
        return cnt ;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL or head->next == NULL) return head;
        int len = findLen(head) ;
        
        ListNode* dummy = new ListNode(0) ;
        dummy->next = head;
        
        ListNode *pre = dummy, *curr , *next;
        
        while(len >= k){
            
            curr = pre->next ;
            next = curr->next ;
            
            for(int i = 1 ; i < k ; i++){
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            
            pre = curr;
            len -= k;
        }
        
        
        return dummy->next;
    }
};
