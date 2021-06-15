// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
// Time complexity: O(n), n = size of string
// Space complexity: O(n) + O(n) = O(n), n = size of string

// Question: Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Approach: Use stack and queue to solve this problem, pop Stack and dequeue Queue, if they are empty, then it's a palindrome.

class Solution {
public:
    bool isPalindrome(string s)
    {
        queue<char> sQueue;
        stack<char> sStack;

        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                sQueue.push(tolower(s[i]));
                sStack.push(tolower(s[i]));
            }
        }

        int j = sQueue.size();

        for(int i = 0; i < j; i++)
        {
            if(sQueue.front() == sStack.top())
            {
                sQueue.pop();
                sStack.pop();
            }
        }

        if(sQueue.size() == 0 && sStack.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
