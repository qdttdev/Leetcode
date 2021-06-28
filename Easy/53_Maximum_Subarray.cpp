// https://leetcode.com/problems/maximum-subarray/
// TC: O(n), n = size of nums
// SC: O(1)

// Question: Given an integer array nums, find the contiguous subarray
// (containing at least one number) which has the largest sum and return its sum.

// Approach: Kadane's Algorithm
// There are two variables: sum for calculating sum the largest sum,max for saving the largest sum.
// We will start summing from the start of the vector and update max if max < sum.
// However, if sum < 0, then we reset sum = 0

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int max = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
                       
            if(max < sum)
            {
                max = sum;
            } 
            
            if(sum < 0)
            {
                sum = 0;
            }
        }
        
        return max;
    }
};
