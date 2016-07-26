class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mymap;
        vector<vector<string>> output;
        string temp;
        int i = 0;
        for (string s : strs) {
            temp = s; 
            sort(temp.begin(), temp.end());
            if (!mymap.count(temp)) {
                vector<string> in(1,s);
                output.push_back(in);
                mymap[temp] = i;
                i++;
            }
            else {
                output[mymap[temp]].push_back(s);
            }
        }
        return output;
    }
};