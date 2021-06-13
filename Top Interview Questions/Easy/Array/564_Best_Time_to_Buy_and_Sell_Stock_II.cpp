// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
// Time complexity: O(n), n = size of prices
// Space complexity: O(1)

// Question: You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Approach: Compare two elements that are next to each other, since we buy before we sell, if buy is lower than sell, then profits are made.

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxProf = 0;
        
        // Traverse through the array until the second last element
        // to make sure prices[j] will not be out of bound
        for(int i = 0, j = 1; i < prices.size()-1; i++, j++)
        {
            // We only profit when prices sold is higher than prices bought
            // and we have to buy in the day before we sell it: pricesBuy < pricesSell
            if(prices[i] < prices[j])
            {
                maxProf += prices[j] - prices[i];
            }
        }
        
        return maxProf;        
    }
};
