// https://leetcode.com/problems/palindrome-number/

// Question: Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

// Approach:  1. I can either use a queue and a stack, populate them with the string, pop the stack and dequeue the queue, if they're empty at the end, then it is Palindrome.
//            2. I can traverse through half of the string, use i = firstIndex, j = endIndex, then compare them, if at any point they're not equal, then it is not Palindrome.

// Approach #2
// TC: O(n), n = length/2 of x
// SC: O(1)

class Solution {
public:
    bool isPalindrome(int x) 
    {
        string xstr = to_string(x);

        for(int i = 0, j = xstr.length()-1; i < xstr.length()/2; i++, j--)
        {
            if(xstr[i] != xstr[j])
            {
                return false;
            }
        }
        
        return true;
    }
};

// Approach #1
// TC: O(n), n = length of x
// SC: O(n), n = length of x

// bool isPalindrome(int x) 
// {
//     queue<char> qX;
//     stack<char> sX;

//     for(int i = 0; i < xstr.length(); i++)
//     {
//         qX.push(xstr[i]);
//         sX.push(xstr[i]);
//     }

//     for(int i = 0; i < xstr.length(); i++)
//     {
//         if(qX.front() == sX.top())
//         {
//             qX.pop();
//             sX.pop();
//         }
//     }

//     if(qX.empty() && sX.empty())
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
