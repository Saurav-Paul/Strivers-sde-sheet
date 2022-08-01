/**
 //https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* starting_point = new ListNode();
        
        starting_point->next = head;
        
        ListNode *fast, *slow;
        
        fast = slow = starting_point;
        
        for(int i = 0 ; i < n ; i++){
            fast = fast->next ;
        }
        
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next ;
        }
        
        slow->next = slow->next->next ;
        
        
        return starting_point->next;
    }
};
