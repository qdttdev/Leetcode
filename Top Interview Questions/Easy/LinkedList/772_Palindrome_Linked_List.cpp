// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/

// Question: Given the head of a singly linked list, return true if it is a palindrome.

// Approach: Reverse the second half of the list then compare from 'start' and 'mid.'

// Original:  1 -> 2 -> 3 -> 3 -> 2 -> 1
// Reversed:  1 -> 2 -> 3 -> 1 -> 2 -> 3
// Compare:   *              *

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
    ListNode* reverse(ListNode* head) // TC: O(n), n = list size
    {                                 // SC: O(1), no extra memory allocated
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        
        while(curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        return head;
    }
    
    bool isPalindrome(ListNode* head) // TC: O(n), n = list size
    {                                 // SC: O(1), no extra memory allocated
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;    // go through 2 nodes at a time
            slow = slow->next;          // go through 1 node at a time
        }
        
        slow = reverse(slow); // slow is at mid of list, reverse list from mid to end
        fast = head;
        
        // Compare start of list and mid of list reversed
        while(slow != nullptr)
        {
            if(slow->val != fast->val)
            {
                return false;
            }
            
            // Move on to compare the next pairs
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};
