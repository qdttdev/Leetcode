// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/

// Question: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, 
// instead you will be given access to the node to be deleted directly.
// It is guaranteed that the node to be deleted is not a tail node in the list.

// Approach: Since we do not have access to the head to find the prev node, we will copy the value of the next node to current node, and delete the next node.

//      *               
// 1 -> 2 -> 3 -> 4     Goal: Delete 2
// 1 -> 3 -> (3) -> 4   Copy value of the next node (3) into delNode (2)
// 1 -> 3 -> 4          Delete the next node (3)

// This method works since it's guaranteed to have 2 nodes in list, and delNode is not tail

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
    void deleteNode(ListNode* node) // TC: O(1)
    {                               // SC: O(1), no extra memory allocate        
        // This node points to the next node
        ListNode* copy = node->next;
        
        // Replace the value of current node by the next node
        node->val = copy->val;
        
        // Skip the next node in the list
        node->next = node->next->next;
        
        // Delete the next node
        delete copy;       
    }
};
