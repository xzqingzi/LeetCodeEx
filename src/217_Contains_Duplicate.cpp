class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> Myset;
        for (int i=0; i<nums.size(); i++) {
            if (Myset.count(nums[i])) return true;
            else {Myset.insert(nums[i]);}
        }
        return false;
    }
};


class Solution {  // Faster, Why
public:
    bool containsDuplicate(vector<int>& nums) {
        if (!nums.size()) return false;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};