// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/

// Question: Merge two sorted linked lists and return it as a sorted list. 
// The list should be made by splicing together the nodes of the first two lists.

// Approach: Choose one list to be the starting point, then find the right head by comparing the first elements.
// Traverse through both lists, compare value of l1 and l2, only increment to next node after arranging the
// smaller node. When one of the lists become null, stop arranging and append the rest of the other list.

// *                     *               *                    *               *
// 1 -> 2 -> 5      1 -> 2 -> 5     1 -> 2 -> 5     1 -> 2 -> 5     1 -> 2 -> 5     
// 1 -> 3 -> 6      1 -> 3 -> 6     1 -> 3 -> 6     1 -> 3 -> 6     1 -> 3 -> 6
// *                *                    *               *                    *

// 1 -> 1 -> 2 -> 3 -> 5 -> 6

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) // TC: O(n1+n2), n1 = size of l1, n2 = size of l2
    {                                                   // SC: O(1), no extra memory allocated
        // If one of the lists is empty, return the other list
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        // Choose a starting point
        ListNode* head = l1;        
        if(l1->val > l2->val)
        {
            head = l2; // update head because l2 is smaller
            l2 = l2->next; // increment l2 because we just put head in list
        }
        else
        {
            l1 = l1->next; // increment l1
        }
        
        // Traverse through the two lists, increment smaller list after comparison
        ListNode* curr = head;        
        while(l1 != nullptr && l2 != nullptr)
        {
            // Next element in list will be the smaller node
            // Increment the used list
            if(l1->val > l2->val) 
            {                
                curr->next = l2;
                l2 = l2->next;
            }
            else
            {
                curr->next = l1;
                l1 = l1->next;
            }
            
            curr = curr->next;
        }
        
        // If one of the lists is nullptr, append the rest of other list
        if(l1 == nullptr) curr->next = l2;
        else curr->next = l1;
            
        return head;
    }
};
