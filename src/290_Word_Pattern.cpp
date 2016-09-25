class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int begin = 0, space = str.find(" ");
        if(space == string::npos && pattern.size() == 1)
            return true;
        else if(space == string::npos)
            return false;
        unordered_map<string, char> hashword;
        unordered_map<char, string> hashchar;
        
        for(int i=0; i<pattern.size(); ++i){

            string word = str.substr(begin, space-begin);
            
            if (!hashword.count(word) && !hashchar.count(pattern[i]) ) {
                hashword[word] = pattern[i];
                hashchar[pattern[i]] = word;
            }
            else if ( !hashword.count(word) || !hashchar.count(pattern[i]) ) {return false;}
            else if ( hashword[word] != pattern[i]  || hashchar[pattern[i]] != word) {return false;}
            
            begin = space+1;
            space = str.find(" ", begin+1);            
        }
        space = str.find_last_of(" ");
        return begin > space && space != string::npos? false: true;
    }
};