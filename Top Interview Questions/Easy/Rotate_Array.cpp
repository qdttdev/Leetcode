class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> numsCopy;    
        
        // After k rotations, the numbers will be in the beginning positions
        // we use mod to eliminate this repetitions
        int j = k % nums.size(); 
        
        if(nums.size() > 1)
        {
            // The rotated elements will be at front
            for(int i = nums.size()-j; i < nums.size(); i++)
            {
                numsCopy.push_back(nums[i]);
            }

            // Push back the rest that hasn't been rotated
            for(int i = 0; i < nums.size()-j; i++)
            {
                numsCopy.push_back(nums[i]);
            }

            // Update nums to hold new rotated value
            for(int i = 0; i < numsCopy.size(); i++)
            {
                nums[i] = numsCopy[i];
            } 
        }             
    }
};

// --- Exceeded Time Limit ---
// for(int i = 0; i < k; i++)
// {
//     nums.insert(nums.begin(), nums.at(nums.size()-1));
//     nums.erase(nums.begin() + nums.size()-1);
// } 
