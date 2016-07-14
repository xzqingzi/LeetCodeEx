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


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0, j=0;
        vector<int> outlist;
        while(i< nums1.size() && j<nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {
                if ( !outlist.size() || nums1[i] != outlist.back()) {  
                    // Can NOT be (nums1[i] != outlist.back()||!outlist.size()) , cause runtime error, 
                    //Or statment must check !outlist.size() first, 
                    outlist.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return outlist;
    }
};


//  Others code 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2) //means loop the vector nums based on iterator, since use auto a can be any type of values
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};