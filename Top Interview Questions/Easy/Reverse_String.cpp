// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
// Time complexity: O(n/2), n is size of the string
// Space complexity: O(1), no extra space allocated

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        char temp;
        
        for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};
