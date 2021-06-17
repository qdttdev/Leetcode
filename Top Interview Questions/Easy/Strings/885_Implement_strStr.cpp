// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/
// Time complexity: O(n), n = length of haystack string
// Space complexity: O(1)

// Question: Return the index of the first occurrence of needle in haystack, 
// or -1 if needle is not part of haystack.

// Approach: Traverse through the haystack and compare the substring of haystack with needle,
// substring length is the same as needle length.
// Return 0 when haystack = needle because the first occurence is found.
// Return -1 when haystack < needle, because occurence can't be found.

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int j = -1;

        if(haystack == needle)
        {
            return 0;
        }
        else if (haystack.length() < needle.length())
        {
            return -1;
        }

        for(int i = 0; i <= haystack.length() - needle.length(); i++) // Note that we use <= here
        {
            if(haystack.substr(i,needle.length()) == needle)
            {
                j = i;                
                break;
            }
        }

        return j;
    }
};
