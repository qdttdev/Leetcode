// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
// What's the time complexity? - O(n), n = digitsSize by worst case
// What's the space complexity? - O(1), no extra space allocated

// Notice: I also tried to solve this problem by using string, stoi/stol/stoll, and to_string
// but it will give Run Time Error since the input digits will exceed stoll capacity.

// Question: Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.

// Approach: Solve this problem by thinking about doing addition on paper, add 1 by column from right to left.
// If it becomes 10, you have to add one again to the left column. If not, return the number.
// When result's digits exceed the original, change first index value to 1, and push 0 to the end to ensure correct value after the increment.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {    
        // Think of how we do addition on paper:
        // Addition performed by column, where the result's digits haven't exceed the original
        // For example: 199 + 1 = 200 (still 3 digits)
        for(int i = digits.size()-1; i >= 0; i--) 
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits; // Since we only add 1, we can return result here if != 9
            }
        }
        
        // When the result's digits exceed the original
        // For example: 999 + 1 = 1000 (from 3 digits to 4 digits)        
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};
