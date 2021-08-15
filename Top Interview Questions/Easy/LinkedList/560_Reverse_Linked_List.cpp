// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/

// Question: Given the head of a singly linked list, reverse the list, and return the reversed list.

// Approach: Reverse the list by making the next node points back to current node.

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
    
    ListNode* reverseList(ListNode* head)   // TC: O(n), n = list size
    {                                       // SC: O(1), no extra memory allocated
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        // Traverse through the end of the list to swap directions
        while(curr != nullptr)
        {
            // Store 'next' value
            next = curr->next;
            
            // The next value will points to 'prev' to swap directions
            curr->next = prev;
            
            // 'prev' is my current node, and the next node is pointing back to curr
            prev = curr;
            
            // Move to the next node
            curr = next;
        }
        
        // curr is now nullptr for loop to exit, so the last node stored as prev, which is head
        head = prev;
        
        return head;
    }
};
