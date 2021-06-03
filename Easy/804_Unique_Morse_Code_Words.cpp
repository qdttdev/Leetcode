// https://leetcode.com/problems/unique-morse-code-words/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        string temp = "";
        set<string> transformation; // a 'set' is a list of uniqueness so I use it to store the number of different transformations         
        map<char,string> alphabet = 
        {
            {'a', ".-"},
            {'b', "-..."},
            {'c',"-.-."},
            {'d',"-.."},
            {'e',"."},
            {'f',"..-."},
            {'g',"--."},
            {'h',"...."},
            {'i',".."},
            {'j',".---"},
            {'k',"-.-"},
            {'l',".-.."},
            {'m',"--"},
            {'n',"-."},
            {'o',"---"},
            {'p',".--."},
            {'q',"--.-"},
            {'r',".-."},
            {'s',"..."},
            {'t',"-"},
            {'u',"..-"},
            {'v',"...-"},
            {'w',".--"},
            {'x',"-..-"},
            {'y',"-.--"},
            {'z',"--.."}
        };   
        
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(alphabet.find(words[i][j]) != alphabet.end())
                {
                    temp += alphabet[words[i][j]];
                    cout << temp;
                }                
                
            }
            
            transformation.insert(temp);
            temp = "";
        }        
        
        return transformation.size();
    }
};
