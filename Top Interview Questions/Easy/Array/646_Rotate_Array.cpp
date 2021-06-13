// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
// Time complexity: O(n), n = size of nums
// Space complexity: O(n), n = size of nums

// Question: Given an array, rotate the array to the right by k steps, where k is non-negative.

// Approach: After k rotations, the numbers will be in their beginning positions so we use mod to
// minimize the rotations. j = k % nums.size()

// Push the rotated numbers into the returning vector, then push the rest.
// Why is i = nums.size()-j ?
// Recognize that rotating 3 steps mean the last 3 elements are totated to the front,
// so the start index i will start at the 3rd to last element then go to last element in the array.

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> numsCopy;    
        
        // After k rotations, the numbers will be in the beginning positions
        // we use mod to eliminate this repetitions
        int j = k % nums.size(); 
        
        if(nums.size() > 1)
        {
            // The rotated elements will be at front
            for(int i = nums.size()-j; i < nums.size(); i++)
            {
                numsCopy.push_back(nums[i]);
            }

            // Push back the rest that hasn't been rotated
            for(int i = 0; i < nums.size()-j; i++)
            {
                numsCopy.push_back(nums[i]);
            }

            // Update nums to hold new rotated value
            for(int i = 0; i < numsCopy.size(); i++)
            {
                nums[i] = numsCopy[i];
            } 
        }             
    }
};

// --- Exceeded Time Limit ---
// for(int i = 0; i < k; i++)
// {
//     nums.insert(nums.begin(), nums.at(nums.size()-1));
//     nums.erase(nums.begin() + nums.size()-1);
// } 
