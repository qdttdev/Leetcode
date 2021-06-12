// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
// Space complexity: O(n/2), n = integer length
// Time complexity: O(n/2), n = integer length

// Question: Given a signed 32-bit integer x, return x with its digits reversed. 
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// My approach: Convert the integer into the string, reverse the string and convert it back into an integer.
// Use to_string and stoi in the process, catch out_of_range exception for stoi and return 0.

class Solution {
public:
    int reverse(int x)
    {
        // Convert x into a string
        string xstr = to_string(x);

        // Reverse the string by traversing to half of the string,
        // swapping first and last element, then continue by increment first, decrement last
        for(int i = 0, j = xstr.size()-1; i < xstr.size()/2; i++, j--)
        {
            char temp = xstr[i];
            xstr[i] = xstr[j];
            xstr[j] = temp;
        }

        // Try-catch block for stoi out_of_range exception to return 0
        try
        {
            if(x < 0) // Check if negative number to add minus sign
            {
                x = stoi("-" + xstr);
            }
            else
            {
                x = stoi(xstr);
            }
        }
        catch (out_of_range& e)
        {
            return 0;
        }

        return x;
    }
};
