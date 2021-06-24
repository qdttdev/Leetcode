// https://leetcode.com/problems/remove-element/
// TC: O(n^2)
// SP: O(1)

// Question: Remove all occurences of val in the vector.

// Approach: Traverse through the entire vector and remove the occurences of val
// j is the number of iterations and must be less than size
// increment index i only when a match is not found

// I was also thinking about swapping, will come back to it later

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i = 0;
        int k = 0;
        int size = nums.size();
        
        for(int i = 0, j = 0; j < size; j++)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                k++;
            }
            else
            {
                i++;
            }
        }
        
        return size - k;
    }
};
