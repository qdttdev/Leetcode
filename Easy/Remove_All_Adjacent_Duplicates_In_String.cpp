class Solution {
public:
    string removeDuplicates(string s) 
    {
        for(int i = 0; i <= s.length()/2;)
        {
            if(s[i] == s[i+1])
            {
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i = 0;
                cout << s << endl;
            }
            else
            {
                i++;
            }
        }
        
        cout << "s = " << s << endl;
        
        return s;
    }
};
