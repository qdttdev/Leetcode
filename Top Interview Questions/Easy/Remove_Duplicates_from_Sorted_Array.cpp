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
