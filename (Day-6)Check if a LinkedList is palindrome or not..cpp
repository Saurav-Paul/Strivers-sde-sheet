//https://leetcode.com/problems/palindrome-linked-list/submissions/
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
    ListNode* reverseList(ListNode *head){
        ListNode *prev, *curr, *next;
        prev = NULL;
        curr = head;
        
        while(curr != NULL){
            next = curr->next ;
            curr->next = prev;
            prev = curr ;
            curr = next ;
        }
        
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow , *fast ;
        
        slow = head, fast = head;
        
        
        // moving slow element to the middle point
        while(fast !=NULL ){
            slow = slow->next ;
            fast = fast->next ;
            if(fast == NULL) break;
            fast = fast->next ;
        }
        
        
        // now revering from the middle point
        ListNode *middle = slow ;
        ListNode* reversed = reverseList(middle) ;
        
        // matching if this is palimdrome
        while(reversed != NULL){
            if(reversed->val != head->val) return false;

            reversed = reversed->next ;
            head = head->next ;
        }


        return true;
    }
};
