// https://leetcode.com/problems/length-of-last-word/
// TC: O(n), n = size of string s
// SP: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int length = 0;
        
        // right-trim the string
        s.erase(s.find_last_not_of(' ')+1);
        
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                length++;
            }
            else
            {
                break;
            }
        }
        
        return length;
    }
};
