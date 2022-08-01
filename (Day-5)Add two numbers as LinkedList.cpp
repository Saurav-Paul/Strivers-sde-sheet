//https://leetcode.com/problems/add-two-numbers/submissions/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        int carry = 0;
        
        ListNode* start = l1 ;
        ListNode* prev;
        
        while(l1 != NULL and l2!=NULL){
            int temp = l1->val + l2->val + carry;
            carry = temp / 10 ;
            temp = temp % 10;
            
            l1->val = temp;
            l2->val = temp;
            
            prev = l1 ;
            l1 = l1->next ;
            l2 = l2->next ;
            

        }
        
        while(l1 != NULL){
            int temp =  l1->val + carry;
            carry = temp / 10 ;
            temp = temp % 10;
            l1->val = temp;
            prev = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL){
            prev->next = l2 ;
            cout << carry << endl;
            
            while(l2 != NULL){
                int temp =  l2->val + carry;
                carry = temp / 10 ;
                temp = temp % 10;
                l2->val = temp;
                prev = l2;
                l2 = l2->next ;
            }
            
        }
        
        if(carry){
            ListNode* temp = new ListNode() ;
            temp->val = carry;
            temp->next = NULL;
            prev->next = temp;
        }
        cout << carry << endl;

        
        return start;
    }
};
