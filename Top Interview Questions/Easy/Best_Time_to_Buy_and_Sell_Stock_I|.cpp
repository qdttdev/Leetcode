// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
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
