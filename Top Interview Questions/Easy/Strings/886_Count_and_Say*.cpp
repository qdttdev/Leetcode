// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/

// Question: Implement countAndSay 
//  1.     1                    one 1                   11
//  2.     11                   two 1                   21
//  3.     21                   one 2, one 1            1211
//  4.     1211                 one 1, one 2, two 1     111221
//  5.     111221               ...
//  6.     312211
//  7.     13112221
//  8.     1113213211
//  9.     31131211131221
// 10.     13211311123113112211

// Recursion visualization for better understanding: n = 3
// string countAndSay(3)                        Line 1
// 	recur(countAndSay(2))                       Line 2
// 		recur(countAndSay(1))                   Line 3
// 			return 1                            Line 4			
		
// countAndSay(1) = "1" from line 4, now proceed line 3 		
//      recur(countAndSay(1)) = recur(1)
// 				 (count and say)
//      result = "" + '1' + '1' = 11

// countAndSay(2) = "11" from line 3, now proceed line 2
//      recur(countAndSay(2)) = recur(11)
//      result = "" + '2' + '1' = 21

// countAndSay(3) = "21" from line 2.	

class Solution {
public:
    
    string recur(string s)
    {
        int count = 0;
        string result = "";
        
        for(int i = 0; i < s.size(); i++)
        {
            // This is the first occurence of s[i]
            count++;
            
            // If the next element isn't the same, then we can put "count" into the result
            if(s[i] != s[i+1])
            {
                // This says, for example: two 1's, result will be 21
                result = result + char('0' + count) + s[i];
                
                // Reset count for next count for a different element
                count = 0;
            }            
        }
        
        return result;
    }
    
    string countAndSay(int n) 
    {
        // Base case: n = 1
        if(n == 1)
        {
            return "1";
        }
        
        // To generate the nth term, just countAndSay the (n-1)th term
        return recur(countAndSay(n-1));            
    }
};
