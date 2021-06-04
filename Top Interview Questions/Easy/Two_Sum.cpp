// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
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

// What's the time complexity? - O(n^2)
// What's n? - Size of nums
// What's the space complexity? - Constant: O(1)
// Look into Set, Map !!!!
