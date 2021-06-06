// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
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
