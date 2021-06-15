// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/
// Time complexity: O(n), n = length of string
// Space complexity: O(n), n = length of string

// Question:    Implement the myAtoi(string s) function, which converts a string to a 32-bit 
//              signed integer (similar to C/C++'s atoi function).
// The algorithm for myAtoi(string s) is as follows:
// 1.   Read in and ignore any leading whitespace.
// 2.   Check if the next character (if not already at the end of the string) is '-' or '+'. 
//      Read this character in if it is either. This determines if the final result is negative 
//      or positive respectively. Assume the result is positive if neither is present.
// 3.   Read in next the characters until the next non-digit charcter or the end of the input 
//      is reached. The rest of the string is ignored.
// 4.   Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits 
//      were read, then the integer is 0. Change the sign as necessary (from step 2).
// 5.   If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp 
//      the integer so that it remains in the range. Specifically, integers less than -2^31 
//      should be clamped to -2%31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
// 6.   Return the integer as the final result.

// Approach: Convert each digit inside the string into an int, sum of (value * 10^column), column value is counted from right to left.
// Example: 123 = (1*100) + (2*10) + (3*1) = 100 + 20 + 3

// The most challenging thing for me was the logic to check for leading space, signs, to ensure that we stop reading based on the rules correctly.

class Solution {
public:
    int myAtoi(string s)
    {
        vector<int> sV;
        int si = 0;
        bool isPositive = true;
        bool isLeadingSpace = true;
        bool isRead = false;

        // Traverse through the string to convert char to int
        // Because it is a digit character, we can do: digit - '0' to achieve the integer value of the digit
        for(int i = 0; i < s.length(); i++)
        {
            // We ignore leading white space, when a character that's not a space is found, it no longer has leading white space
            if(s[i] != ' ')
            {
                isLeadingSpace = false;
            }

            // We read '-' or '+' to decide if this number is negative or positive
            if(s[i] == '-' || s[i] == '+')
            {
                if(isRead == true) // If we find a sign but we're already reading, stop reading and exit loop
                {
                    break;
                }
                
                if(s[i] == '-') // This number is negative
                {
                    isPositive = false;
                }
                
                isRead = true; // Now we start reading, the next character has to be a digit
            }
            // If it is not a digit, and not a leading white space, then we stop reading and exit loop 
            else if(!isdigit(s[i]) && !isLeadingSpace)
            {
                break;
            }

            // If it is a digit, we push it in vector sV
            if(isdigit(s[i]))
            {
                isRead = true; // Now we start reading, the next character has to be a digit
                sV.push_back(s[i] - '0');
            }
        }

        // Traverse through vector, and sums of (digit * 10^column), column is counted from right to left
        for(int i = 0, j = sV.size()-1; i < sV.size(); i++, j--)
        {
            // If the summation is overflow INT_MAX or INT_MIN, then we clamp value to either INT_MAX or INT_MIN
            if(si + sV[i] * pow(10,j) > INT_MAX || -1*(si + sV[i] * pow(10,j)) < INT_MIN)
            {
                if(isPositive)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
                break;
            }

            si += sV[i] * pow(10,j);
        }
      
        if(!isPositive)
        {
            si *= -1;
        }
        return si;
    }
};
