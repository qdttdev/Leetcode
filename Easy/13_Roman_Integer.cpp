class Solution {
public:
    int singleRomToInt(char c)
    {
        int iVal = 0;
        
        switch(c)
        {
            case 'I': iVal = 1;
            break;
                
            case 'V': iVal = 5;
            break;
                
            case 'X': iVal = 10;
            break;
                
            case 'L': iVal = 50;
            break;
                
            case 'C': iVal = 100;
            break;
                
            case 'D': iVal = 500;
            break;
                
            case 'M': iVal = 1000;
            break;
        }
        
        return iVal;
    }
    
    int romanToInt(string s) 
    {
        int iVal = singleRomToInt(s[0]);
        
        for(int i = 1; i < s.length(); i++)
        {         
            if(s[i-1] == 'I' && (s[i] == 'V' || s[i] == 'X')
            || s[i-1] == 'X' && (s[i] == 'L' || s[i] == 'C')
            || s[i-1] == 'C' && (s[i] == 'D' || s[i] == 'M')   
              ) 
            {
                iVal += singleRomToInt(s[i]) - singleRomToInt(s[i-1]);
            }
            else
            {
                iVal += singleRomToInt(s[i]);
            }      
            
            cout << iVal << endl << endl;
        }
        
        if(iVal < 0)
        {
            iVal = iVal*-1;
        }
        
        return iVal;
    }
};
