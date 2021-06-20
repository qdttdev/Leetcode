// https://leetcode.com/problems/add-binary/

// Question: Sum 2 binary strings

// Approach: Add them by column

class Solution {
public:    
    
    string addBinary(string a, string b) 
    {
    int carry = 0;
    int temp = 0;
    string result = "";
    string big = "";
    string small = "";
    
    if(a.size() > b.size())
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }
    
    for(int i = big.size()-1, j = small.size()-1; i < big.size(); i--, j--)
    {
        if(j < 0)
        {
             temp = (big[i]-'0') + carry;
        }
        else
        {
            temp = (big[i]-'0') + (small[j]-'0') + carry;
        }
        
        carry = 0;
        
        if(temp == 0)
        {
            result = "0" + result;
        }
        else if(temp == 1)
        {
            result = "1" + result;
        }
        if(temp > 1)
        {
            result = to_string(temp%2) + result;
            carry = 1;
        }
    }
    
    if(carry == 1)
    {
        result = "1" + result;
    }
    
    return result;
}
};
