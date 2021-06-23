// https://leetcode.com/problems/roman-to-integer/
// TC: O(n), n = length of string
// SC: O(1), no extra space allocated

// Question: Convert Roman numerals into integer.

// Approach: Use switch statements to store value of each Roman symbols.
// Then use if statements for the six cases for subtraction.
// Subtract twice because we added it from previous iteration.

class Solution {
public:
    int singleRomToInt(char c)
    {
        int iVal = 0;
        
        switch(c)
        {
            case 'I': iVal = 1;
            break;
                
            case 'V': iVal = 5;
            break;
                
            case 'X': iVal = 10;
            break;
                
            case 'L': iVal = 50;
            break;
                
            case 'C': iVal = 100;
            break;
                
            case 'D': iVal = 500;
            break;
                
            case 'M': iVal = 1000;
            break;
        }
        
        return iVal;
    }
    
    int romanToInt(string s) 
    {
        int iVal = singleRomToInt(s[0]);
        
        for(int i = 1; i < s.length(); i++)
        {         
            if(s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X')
            || s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C')
            || s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M')   
              ) 
            {
                iVal += singleRomToInt(s[i]) - 2*singleRomToInt(s[i-1]);
            }
            else
            {
                iVal += singleRomToInt(s[i]);
            }      
        }
        
        return iVal;
    }
};
