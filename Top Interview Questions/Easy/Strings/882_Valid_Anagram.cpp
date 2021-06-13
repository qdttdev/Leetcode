// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
// Time complexity: O(n) + O(nlogn) + O(nlogn) = O(nlogn), n = string length
// Space complexity: O(n), n = string length

// Question: Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Anagram is a word formed by rearrange the letters: cinema = iceman

// Approach: Recognize that if strings aren't the same length, they are not anagrams.
// Then, I sort the strings and compare them, if they are equal, then they are anagrams.

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        vector<char> sV;
        vector<char> tV;
        
        // If the strings aren't the same length, they are not anagrams
        if(s.length() != t.length())
        {
            return false;
        }
        
        // Populate the vectors with strings s and t
        for(int i = 0; i < s.length(); i++)
        {
            sV.push_back(s[i]);
            tV.push_back(t[i]);
        }
        
        // Sort strings s and t
        sort(sV.begin(),sV.end());
        sort(tV.begin(),tV.end());
        
        // If the sorted vector are equal, they are anagrams
        if(sV == tV)
        {
            return true;
        }
        else
        {
            return false;
        }                
    }
};
