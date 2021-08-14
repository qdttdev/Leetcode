// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

// Question: Given the head of a linked list, remove the nth node from 
// the END of the list and return its head.

// Approach: Traverse through list to find listSize, then skip size-n elements and delete.

// 1 -> 2 -> 3 -> 4 -> 5,   n = 2: delete 4
// 1 -> 2 -> 3 -> 5         Notice: Skipping 5-2 = 3 first elements

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* curr = nullptr;
        int size = 0;
        int skip = 0;
        
        // Do not need to check if list is empty because there's at least 1 node based on condition       
        
        // Find size of list
        curr = head;
        while(curr != nullptr)
        {
            size++;
            curr = curr->next;
        }
        
        // Find the number of elements skipped
        skip = size - n;
        
        // Skip through skip-1 elements because we want curr before delNode
        curr = head;        
        for(int i = 1; i < skip; i++)
        {
            curr = curr->next;
        }
        
        ListNode* delNode = nullptr;
        
        // Delete at the front: when size == n, we remove the first node and update head
        if(size == n)
        {
            delNode = curr;
            head = head->next;
        }
        // Delete in the middle/ end
        else
        {
            delNode = curr->next;
            curr->next = curr->next->next;  
        }        
              
        delete delNode;
        
        return head;
    }
};
