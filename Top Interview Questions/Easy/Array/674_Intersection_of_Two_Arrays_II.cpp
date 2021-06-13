// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/
// What's the time complexity? - O(n*m), n = smallerSize, m = biggerSize
// What's the space complexity? - O(n), n = the numbers in the intersection

// Question: Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Approach: We use the smaller-size array to check for intersections.
// Use two loops, smaller-size array as outer, bigger-size array as inner.
// Compare element of smaller == bigger, if exist, then erase it from bigger to prevent duplicates,
// and push that element in the returning vector.

class Solution {
public: 
    
    vector<int> smallerIntersection(vector<int>& smaller, vector<int>& bigger)
    {
        vector<int> interV;
        int j = 0;

        // Use smaller as base case to traverse to find intersections
        for(int i = 0; i < smaller.size(); i++)
        {
            // Traverse through bigger to find matches
            while(j < bigger.size())
            {
                // If match is found, erase it from bigger to prevent duplicates
                // Push back into the returning array interV
                // Break because we don't need to compare with the rest of bigger
                if(smaller[i] == bigger[j])
                {
                    bigger.erase(bigger.begin()+j);
                    interV.push_back(smaller[i]);
                    break;
                }
                else // Increment to see if match is found in next element in bigger
                {
                    j++;
                }
            }
            
            // Reset j for the next traversal through j for new i
            j = 0;
        }
        
        return interV;        
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        // It makes sense to use the smaller-size array to check for intersections       
        if(nums1.size() <= nums2.size())
        {
            return smallerIntersection(nums1, nums2);
        }
        else
        {
            return smallerIntersection(nums2, nums1);
        }
    }
};
