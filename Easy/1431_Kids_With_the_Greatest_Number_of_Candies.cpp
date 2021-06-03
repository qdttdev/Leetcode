// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> output;
        int maxCandy = 0;
        
        // Find the greatest number of candies among them
        auto it = max_element(std::begin(candies), std::end(candies));
        maxCandy = *it;
        
        for(int i = 0; i < candies.size(); i++)
        {
            // If add extra candies exceed the maxCandy, we have new maxCandy
            // push it into the output vector to return
            if(candies[i] + extraCandies >= maxCandy)
            {
                output.push_back(true);
            }
            else
            {
                output.push_back(false);
            }
        }
        
        return output;
    }
};
