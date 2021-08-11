// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head)    // TC: O(n), n = list size
    {                                       // SC: O(1), no extra memory allocated
        ListNode* curr = head;
        ListNode* midNode = NULL;
        int count = 0;
        int mid = 0;
        
        // Traverse through the list to count elements
        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        
        // Round mid, i.e. 5/2 = 3
        mid = ceil(count/2.0);

        // If the number of elements is even, mid is the second middle node
        if(count % 2 == 0)
        {
            mid++;
        }
        
        // Traverse through the list until mid and return
        curr = head;
        for(int i = 1; i <= mid; i++)
        {
            if(i == mid)
            {
                midNode = curr;
            }
            curr = curr->next;
        }
        
        return midNode;
    }
};
