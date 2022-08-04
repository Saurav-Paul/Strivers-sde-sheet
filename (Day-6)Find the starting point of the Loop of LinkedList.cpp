//https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow, *entry;
        fast = slow = entry = head ;
        
        if(fast == NULL) return NULL;
        
        while(fast != NULL){

            slow = slow->next ;
            fast = fast->next ;
            if(fast == NULL) break;
            fast = fast->next ;
            if(fast == slow) break ;
        }
        
        
        if(fast != NULL){
            cout << fast->val << " " << slow->val << " " << entry->val << endl;
            while(slow != NULL){
                if(entry == slow) return slow ;
                entry = entry->next ;
                slow = slow->next ;
            }
        }
        
        return NULL;
    }
};
