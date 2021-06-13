// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
// Time complexity: O(n) + O(n) = O(n), n = size of nums
// Space complexity: O(n), n = size of nums for the map

// Description: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Approach: Use map to count for occurences of the number in the array, then output the one with 1 occurence.

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        map<int,int> counter; // counter <value,count>
    
        for(int i = 0; i < nums.size(); i++)
        {
            // If not found, this will be first count
            if(counter.find(nums[i]) == counter.end())
            {
                counter[nums[i]] = 1;

            }
            else
            {
                counter[nums[i]]++;
            }
        }

        int single = 0;
        for(auto it = counter.begin(); it != counter.end(); it++)
        {
        // it->first  = key (num)
        // it->second  = value (count)    
            if(it->second == 1)
            {            
                single = it->first;
            }
        }

        return single;
    }
};
