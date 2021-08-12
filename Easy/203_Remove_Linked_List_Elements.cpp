// https://leetcode.com/problems/remove-linked-list-elements/submissions/

// Notes for this problem:
// - Account for case list is empty (line #27)
// - Separate 'remove head' and 'remove middle' (lines #33 and #42)
// - Not to access NULL memory i.e. try curr->next->val but curr->next is null (line #45)
// - Free unused memory using 'delete'

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
    ListNode* removeElements(ListNode* head, int val)   // TC: O(n), n = list size
                                                        // SC: O(1), no extra memory allocated
    {
        ListNode* curr = NULL;
        ListNode* delNode = NULL;
        
        // If list is empty, return
        if(head == NULL)
        {
            return head;
        }
        
        // If the first element is equal to val, remove head
        while(head != NULL && head->val == val)
        {
            curr = head;            
            delNode = curr;
            head = head->next; // update head
            delete delNode;      
        }
        
        curr = head;        
        while(curr != NULL)
        {             
            // If the middle element is equal to val
            if(curr->next != NULL && curr->next->val == val)
            {
                // delNode is the next node to be deleted
                delNode = curr->next;
                
                // Skip delNode 
                curr->next = curr->next->next;
                
                // Delete the node
                delete delNode;
            }
            else
            {
                curr = curr->next;
            }            
        }
        
        return head;
    }
};
