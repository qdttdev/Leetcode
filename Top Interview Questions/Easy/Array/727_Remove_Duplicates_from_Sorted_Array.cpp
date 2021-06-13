// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
// Time complexity: O(n), n = size of nums
// Space complexity: O(1)

// Question: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. Since it is impossible to change the length of the array in some languages, you must instead 
// have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first 
// k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
// Return k after placing the final result in the first k slots of nums.
// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Approach: Since the array is sorted, compare two elements that are next to each other and remove them if duplicate.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // Handle edge case: What if size of nums is 0?
        if(nums.size() == 0)
        {
            return 0;
        }
        
        // Handle egde case: What if size of nums is 1?
        if(nums.size() == 1)
        {
            return 1;
        }
        
        int i = 0;  // left element
        int j = 1;  // right element
        
        // Traverse through the whole array until the second last element
        // to make sure nums[j] is not our of bound
        while(i < nums.size()-1) 
        {
            // When duplicates found, delete one of them
            if(nums[i] == nums[j])
            {
                nums.erase(nums.begin()+j);
            }
            
            // Increment when duplicates not found because index stays the same 
            // but value is updated because of deletion
            else 
            {
                i++;
                j++;
            }
        }
        
        return nums.size();
    }
};
