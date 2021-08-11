// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head)   // TC: O(n), n = size of list
    {                                       // SC: O(1), no extra memory created
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
      
        while(curr != NULL)
        {
            // Store 'next' to traverse the list
            next = curr->next;
            
            // The next node points to the 'prev' node, NOTE: prev = NULL atm
            curr->next = prev;
                
            // The 'prev' node is at 'curr'
            prev = curr;
            
            // Move to the next node using the stored 'next'
            curr = next;
        }
        
        // head = prev, not head = curr because prev stores the last value of curr before end of list
        head = prev;
        
        return head;
    }
};
