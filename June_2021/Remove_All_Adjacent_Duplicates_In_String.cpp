// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3794/
// TC: O(n), n = length of string
// SC: O(1)

// Question: Remove adjacent duplicates in a string.

// Approach: Traverse through the string and remove adjacent elements, then reset i = 0. If not found then increment i.

class Solution {
public:
    string removeDuplicates(string s) 
    {
        for(int i = 0; i < s.length()-1;)
        {
            if(s[i] == s[i+1])
            {
                if(s == "")
                {
                    return s;
                }
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i = 0;
            }
            else
            {
                i++;
            }
        }
        
        return s;
    }
};
