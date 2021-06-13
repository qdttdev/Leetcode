// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
// What's the time complexity? - O(n^2), n = size of nums array
// What's the space complexity? - Constant: O(1), no extra memory allocated

// Question: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Approach: Sum the array by using two for loops and add each integer to the entire array to check for target.
// There is another approach for this problem, will need to redo.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i = 0; i < nums.size(); i++)
        {           
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        
        return {};
    }
};
