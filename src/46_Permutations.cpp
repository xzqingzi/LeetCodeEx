class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        iteratePermute(nums, 0, output);
        return output;
    }
    void iteratePermute(vector<int>& num, int begin, vector<vector<int>>& output ) {
        if (begin >= num.size()-1) {
            output.push_back(num);
            return;  //not need to output the maxtrix 'output'
        }
        for(int i=begin; i<num.size(); i++) {
            swap(num[begin], num[i]);
            iteratePermute(num, begin+1, output);
            swap(num[begin], num[i]); //Must reverse back to reset
        }
        
    }
};