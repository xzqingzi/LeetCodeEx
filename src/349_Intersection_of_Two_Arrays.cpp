class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> Myset(nums1.begin(), nums1.end());
        vector<int> outlist;
        for(int i=0; i<nums2.size(); i++) {
            if(Myset.count(nums2[i])) {
                outlist.push_back(nums2[i]);
                Myset.erase(nums2[i]);
            }
        }
        return outlist;
    }
};