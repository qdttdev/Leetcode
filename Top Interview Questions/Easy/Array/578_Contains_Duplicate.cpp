// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
// Time complexity: O(n), n = size of nums
// Space complexity: O(n), n = size of nums

// Description: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Approach: Use map to count, and output if distinct based on count.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        map<int, int> numsMap; // map<number, numCount>
        
        for(int i = 0; i < nums.size(); i++)
        {
            // != end means match NOT FOUND, then this is the first occurence "1"
            if(numsMap.find(nums[i]) == numsMap.end())
            {
                numsMap[nums[i]] = 1;
            }
            else // else if match is FOUND
            {
                numsMap[nums[i]]++; // increment the number of increments
                return true;
            }
        }
        
        return false;
    }
};

// Remember: In Map, you can use 'key' as an index
