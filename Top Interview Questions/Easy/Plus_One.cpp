// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
// What's the time complexity? - O(n), n = digitsSize by worst case
// What's the space complexity? - O(1), no extra space allocated

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
