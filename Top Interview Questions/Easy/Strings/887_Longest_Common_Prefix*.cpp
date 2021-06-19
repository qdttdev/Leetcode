// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/
// Time Comp: O(m*n), m = length of the first string in the vector, n is the number of strings in vector
// Space Comp: O(1), no extra space allocated

// But actually, what's the time complexity of substring?

// Question: Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

//    0123456          
// 0  flower 
// 1  florida
// 2  flour

// Approach: I traverse through the vector by columns, and check for each row to contain
// the substring, if all rows did, then check for next largest substring = col+1

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int col = 0;
        int row = 0;
        int prefLength = 0;
        
        // Go through the columns of the first string, assume first string as base case
        for(col = 0; col < strs[0].size(); col++)
        {
            // Go through all the rows
            for(row = 1; row < strs.size(); row++)
            {
                if(strs[0].substr(0,col+1) != strs[row].substr(0,col+1))
                {
                    break;
                }                
            }
            
            // If all row is check, then prefix length increments
            if(row == strs.size())
            {
                prefLength++;
            }
            else
            {
                break;
            }
        }
        
        return strs[0].substr(0,prefLength);
    }
};
