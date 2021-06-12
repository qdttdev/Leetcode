// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
// Space complexity: O(n), n = length of string
// Time complexity: O(n), n = length of string

class Solution {
public:
    int firstUniqChar(string s) 
    {
        map<char,int> letterCount;
        int first = -1;

        // Traverse through the string and populate map with key = char, val = charCount
        for(int i = 0; i < s.size(); i++)
        {
            if(letterCount.find(s[i]) == letterCount.end())
            {
                letterCount[s[i]] = 1;
            }
            else
            {
                letterCount[s[i]]++;
            }
        }

        // Traverse through the string again and match with map to check for count
        for(int i = 0; i < s.size(); i++)
        {
          // Remember: s[i] (char) can be used as 'index' to search the map
            if(letterCount[s[i]] == 1)
            {
                first = i;
                break;
            }
        }

        return first;
    }
};
