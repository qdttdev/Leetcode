// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
// What's the time complexity? - O(n), n = size of nums
// What's the space complexity? - O(1), no extra memory allocated

// Question: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Approach: Traverse through the array and delete any 0 found and keep track zeroes count.
// Push the deleted zeroes to the back of the array.

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;
        int zeros = 0;
    
        // Traverse through the array, delete any 0s found
        while(i < nums.size())
        {
            if(nums[i] == 0) 
            {
                nums.erase(nums.begin() + i); // Delete 0s, don't increment i because i is updated with new value
                zeros++; // Keep track of the zeros deleted
            }
            else
            {
                i++; // No deletion, move to next index
            }
        }
        
        // Push back the number of zeros
        for(int j = 0; j < zeros; j++)
        {
            nums.push_back(0);
        }
    }
};
