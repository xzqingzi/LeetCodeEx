class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> list;
        for (int n: nums) {
            list.push_back(to_string(n));
        }
        sort(list.begin(), list.end(),comparefunc); 
        string result;
        for (string n: list) {
            result += n;
        }
        if (result[0] == '0') return "0";
        return result;
    }
private:    
    static bool comparefunc(string& l, string& r) {
        if (l+r > r+l) return 1;
        else return 0;
    }
};