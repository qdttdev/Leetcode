// https://leetcode.com/problems/add-binary/
// Time Complexity: O(n), n = size of bigger string
// Space Complexity: O(1), no extra space allocated

// Question: Sum 2 binary strings

// Approach: Add them by column. What confuses me at first was how to deal with sum greater than 1: We use modulus

class Solution {
public:    
    
    string addBinary(string a, string b) 
    {
        int carry = 0;
        int temp = 0;
        string result = "";
        string big = "";
        string small = "";

        // Determine which string is greater in length
        if(a.size() > b.size())
        {
            big = a;
            small = b;
        }
        else
        {
            big = b;
            small = a;
        }

        // Traverse through bigger string, we will do additionby column from right to left
        // so use i = lastIndex of big, j = lastIndex of small, decrement for each iteration
        for(int i = big.size()-1, j = small.size()-1; i < big.size(); i--, j--)
        {
            if(j < 0) // If at the end of the smaller string, we will not add it anymore
            {
                 temp = (big[i]-'0') + carry;
            }
            else
            {
                temp = (big[i]-'0') + (small[j]-'0') + carry;
            }

            // Reset carry because we just used it
            carry = 0;
            
            if(temp == 0)
            {
                result = "0" + result;
            }
            else if(temp == 1)
            {
                result = "1" + result;
            }
            else if(temp > 1)   // If the temp is greater than 1, we will have to carry, the element added will be tempMod2
            {                   // For example: If temp = 2 --> temp%2 = 0, temp = 3 --> temp%2 = 1
                result = to_string(temp%2) + result;
                carry = 1;
            }
        }

        // Since we reset carry after the iteration, if carry = 1, that means we're missing one carry, add it here
        if(carry == 1)
        {
            result = "1" + result;
        }

        return result;
    }
};
