// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
// Time complexity: O(n/2), n is size of the string
// Space complexity: O(1), no extra space allocated

// Question: Write a function that reverses a string. The input string is given as an array of characters s.

// Approach: Traverse through half of the string, swap first and last elements, then increment first, decrement last.
// Use i for first index, j for last index.

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        char temp;
        
        for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};
